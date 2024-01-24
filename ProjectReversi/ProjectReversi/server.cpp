#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define BUFFER_LEN 1000
/*ポート番号は任意のモノを設定*/
#define MY_PORT_NUM 55555

#include "Server.h"
#include "Cell.h"

using namespace std;

Server::Server() {
	listenSocket = INVALID_SOCKET;
}

Server::~Server() {
	Close();
}

int Server::Initialize() {
	WSADATA wsaData;
	return WSAStartup(MAKEWORD(1, 1), &wsaData);
}

void Server::Close() {
	CloseListenSocket();
	WSACleanup();
}

bool Server::OpenListenSocket() {
	listenSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocket == INVALID_SOCKET) {
		cout << "ソケットオープンエラー\n";
		return false;
	}
	cout << "リスンソケットオープン完了\n";

	SOCKADDR_IN saddr;
	ZeroMemory(&saddr, sizeof(SOCKADDR_IN));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(MY_PORT_NUM);
	saddr.sin_addr.s_addr = INADDR_ANY;

	if (bind(listenSocket, (struct sockaddr*)&saddr, sizeof(saddr)) == SOCKET_ERROR) {
		std::cout << "bindエラー\n";
		closesocket(listenSocket);
		return false;
	}
	else
		cout << "bind成功\n";

	if (listen(listenSocket, 0) == SOCKET_ERROR) {
		cout << "listen error\n";
		closesocket(listenSocket);
		return false
			;
	}
	else
		cout << "listen成功\n";

	return true;
}

SOCKET Server::AcceptConnection() {
	SOCKADDR_IN from;
	int fromlen = sizeof(from);
	SOCKET clientSocket = accept(listenSocket, (SOCKADDR*)&from, &fromlen);
	if (clientSocket == INVALID_SOCKET) {
		cout << "accept error\n";
		return INVALID_SOCKET;
	}

	cout << inet_ntoa(from.sin_addr) << "が接続できました\n";

	return clientSocket;
}

void Server::CloseListenSocket() {
	if (listenSocket != INVALID_SOCKET) {
		closesocket(listenSocket);
		cout << "リスンソケットクローズ完了\n";
	}
}

Cell Server::ReceiveData(SOCKET socket, char* buffer, int bufferSize) {
	int rcv = recv(socket, buffer, bufferSize - 1, 0);
	if (rcv == SOCKET_ERROR) {
		cout << "受信エラーです\n";
	}
	else {
		buffer[rcv] = '\0';
	}

	int x = static_cast<int>(buffer[0] - '0');
	int y = static_cast<int>(buffer[1] - '0');

	cout << "受信：" << x<< "," <<y << "\n";
	return Cell(x,y);
}

int Server::SendData(SOCKET socket, const char* data, int dataSize) {
	int sent = send(socket, data, dataSize, 0);
	if (sent == SOCKET_ERROR) {
		cout << "送信エラー\n";
	}
	return sent;
}