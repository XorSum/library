#include "CReader.h"
#include "CBook.h"
#include "CUser.h"
#include <iostream>

int main()
{
	CUser zxr;
	cout << "ABC的" << endl;
	zxr.show();
	CReader hbk;
	hbk.setname("hbk");
	hbk.setcode(123);
	hbk.setbrbook(CBook(233, "hhh"));
	hbk.show();
	std::cout << "hello" << std::endl;
	std::cout << "hello" << std::endl;

}