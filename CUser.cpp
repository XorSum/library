#include "CUser.h"
#include <string>
#include <iostream>
using namespace std;
CUser::CUser()
{

	code = 0;
	name = "unnamed";
}

CUser::CUser(int id, string na)
{
	code = id;
	name = na;
}

void CUser::setcode(int n)
{
	code = n;
}

int CUser::getcode()
{
	return code;
}

void CUser::setname(string na)
{
	name = na;
}

string CUser::getname()
{
	return name;
}

void CUser::show()
{
	cout << "姓名：" << name << "编号：" << code << endl;
}
