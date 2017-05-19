#include "CReader.h"
#include "CBook.h"
#include "CUser.h"
#include "DataBase.h"
#include <iostream>

int main()
{
	CUser zxr;
	cout << "ABC的" << endl;
	zxr.show();
	CReader hbk;
	CReader wjx(250, "zz");
	hbk.setname("hbk");
	hbk.setcode(123);
	CBook book(233, "hhh");
	CBook book2(232343, "hhh");
	hbk.setbrbook(book);
	hbk.show();
	cout << endl;
	DataBase db;
	db.load();
	cout << "iojsdf" << endl;
	db.addbook(book);
	db.addbook(book2);
	db.listbooks();
	db.editbook(0, book2);
	db.listbooks();
	db.delbook(1);
	db.listbooks();
	std::cout << "hello" << std::endl;
	std::cout << "hello" << std::endl;
	db.addreader(wjx);
	db.addreader(hbk);
	db.listreaders();
	db.editreader(0, hbk);
	db.save();
	db.load();
}