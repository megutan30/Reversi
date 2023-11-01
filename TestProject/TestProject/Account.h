// 銀行口座クラス（第４版：ヘッダ部）

#include <string>

class Account {
	std::string full_name;	// 口座名義
	std::string number;		// 口座番号
	long crnt_balance;		// 預金残高

public:
	Account(std::string name, std::string num, long amnt);	// コンストラクタ

	std::string name()  { return full_name; }		// 口座名義を調べる
	std::string no()    { return number; }			// 口座番号を調べる
	long balance()      { return crnt_balance; }	// 預金残高を調べる

	void deposit(long amnt);						// 預ける
	void withdraw(long amnt);						// おろす
};
