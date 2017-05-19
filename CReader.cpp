#include "CReader.h"
#include <iostream>
#include <string>
using namespace std;
CReader::CReader()
{
	Is_Borrowing = true;
	Is_Existing = true;
}

CReader::CReader(int id, string na) :CUser(id, na)
{
	Is_Borrowing = true;
	Is_Existing = true;
}

bool CReader::get_Existing()
{
	return Is_Existing;
}

void CReader::set_Existing(bool is)
{
	Is_Existing = is;
}

bool CReader::get_Borrowing()
{
	return Is_Borrowing;
}

void CReader::set_Borrowing(bool is)
{
	Is_Borrowing = is;
}

void CReader::setbrbook(CBook bt)
{
	brbook = bt;
}

CBook CReader::getbrbook()
{
	return brbook;
}

void CReader::show()
{
	CUser::show();
	cout << "图书名称是" << brbook.getname() <<"图书编号是"<<brbook.getcode()<< endl;
//	cout << Is_Existing << endl;
}
