#ifndef SERVER_H
#define SERVER_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <windows.h>
#include <iostream>
#include "Cell.h"

class  Server
{
public:
    Server();
    ~Server();

    SOCKET listenSocket;
    int Initialize();
    void Close();
    bool OpenListenSocket();
    SOCKET AcceptConnection();
    void CloseListenSocket();
    Cell ReceiveData(SOCKET socket, char* buffer, int bufferSize);
    int SendData(SOCKET socket, const char* data, int dataSize);
private:

};

#endif

