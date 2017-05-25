#include "CReader.h"
#include "CBook.h"
#include <string>
#include <iostream>
using namespace std;
CBook::CBook()
{
	code = 0;
	name = "unnamed";
	Is_Stock = true;
	Is_Existing = true;
}

CBook::CBook(int co, string na)
{
	code = co;
	name = na;
	Is_Stock = true;
	Is_Existing = true;
}

void CBook::setcode(int n)
{
	code = n;
}

int CBook::getcode()
{
	return code;
}

void CBook::setname(string na)
{
	name = na;
}

string CBook::getname()
{
	return name;
}

bool CBook::get_Stock()
{
	return Is_Stock;
}

void CBook::set_Stock(bool is)
{
	Is_Stock = is;
}

bool CBook::get_Existing()
{
	return Is_Existing;
}

void CBook::set_Existing(bool is)
{
	Is_Existing = is;
}

void CBook::show()
{
	
	if (Is_Existing)
	{
		cout << "名称：" << name << " code：" << code;
		if (Is_Stock) cout << " 在架";
		else cout << " 借出";
		cout << endl;
	}
}

