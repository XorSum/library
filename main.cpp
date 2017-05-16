#include "CBookManager.h"
#include "CReaderManager.h"
#include "CReader.h"
#include "CBook.h"
#include "CUser.h"
#include <iostream>

int main()
{
	CUser zxr;
	zxr.show();
	CReader hbk;
	hbk.setname("hbk");
	hbk.setcode(123);
	hbk.setbrbook(CBook(233, "hhh"));
	hbk.show();
	CReaderManager readermanager;
	readermanager.rdarray[10].show();
	std::cout << "hello" << std::endl;
	std::cout << "hello" << std::endl;

}