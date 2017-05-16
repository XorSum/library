#include "CReader.h"
#include "CBook.h"
#include <string.h>
CBook::CBook()
{
	code = 0;
	name = "";
	Is_Stock = false;
	Is_Existing = false;
}

CBook::CBook(int no, string na)
{
	code = no;
	name = na;
	Is_Stock = false;
	Is_Existing = false;
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
