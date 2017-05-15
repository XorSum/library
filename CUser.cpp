#include "CUser.h"
#include <string>
using namespace std;
CUser::CUser()
{
}

CUser::CUser(int id, string na)
{
	code = id;
	name = na;
}

void CUser::setcode(int n)
{
}

int CUser::getcode()
{
	return 0;
}

void CUser::setname(string na)
{
}

string CUser::getname()
{
	return name;
}

void CUser::show()
{
}
