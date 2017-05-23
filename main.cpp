#include "CReader.h"
#include "CBook.h"
#include "CUser.h"
#include "DataBase.h"
#include <iostream>
DataBase db;
int landbook()
{
	string readerName, bookName;
	int readerSubscript, bookSubscript;
	cout << "请输入读者名称" << endl;
	cin >> readerName;
	readerSubscript = db.findreader(readerName);
	if (readerSubscript == -1)
	{
		cout << "读者不存在" << endl;
		return 0;
	}
	cout << "请输入书籍名称" << endl;
	cin >> bookName;
	bookSubscript = db.findbook(bookName);
	if (bookSubscript == -1)
	{
		cout << "书籍不存在" << endl;
		return 0;
	}
	else if (bookSubscript == -2)
	{
		cout << "书籍已借出" << endl;
		return 0;
	}
	db.editbook(bookSubscript, false);
	db.editreader(readerSubscript, db.getbook(bookSubscript));
	db.editreader(readerSubscript, true);
	cout << "借书成功" << endl;
	return 0;
}
int returnbook()
{
	cout << "请输入读者名称" << endl;
	string readername;
	cin >> readername;
	int readersubscript = db.findreader(readername);
	if (readersubscript == -1)
	{
		cout << "读者不存在" << endl;
		return 0;
	}
	string bookname = db.findbook(((db.getreader(readersubscript)).getbrbook()).getname());
	int booksubscript = db.findbook(bookname);
	db.editbook(booksubscript, true);
	db.editreader(readersubscript, false);
	return 0;
}
int bookmanage()
{
	return 0;
}
int readermanage()
{
	return 0;
}
int filemanage()
{
	cout << "1.文件存储" << endl << "2.文件读取" << endl;
	int command;
	cin >> command;
	if (command == 1)
	{
		cout << "请输入文件名，默认为data.db" << endl;
		string filename;
		cin >> filename;
		db.save(filename);
		cout << "文件已存储" << endl;
		return 0;
	}
	else if (command == 2)
	{
		cout << "请输入文件名，默认为data.db" << endl;
		string filename;
		cin >> filename;
		db.load(filename);
		cout << "文件已读取" << endl;
		db.listbooks();
		db.listreaders();
		return 0;
	}
	else
	{
		cout << "文件未操作" << endl;
		return 1;
	}
}
int main()
{
	cout << "欢迎使用图书馆管理系统" << endl;
	cout << "1.借书" << endl;
	cout << "2.还书" << endl;
	cout << "3.图书管理" << endl;
	cout << "4.读者管理" << endl;
	cout << "5.文件存储" << endl;
	cout << "其他退出" << endl;
	int flag = 1;
	while (flag)
	{
		int command=0;
		cin >> command;
		switch (command)
		{
		case 1:
			landbook();
			break;
		case 2:
			returnbook();
			break;
		case 3:
			bookmanage();
			break;
		case 4:
			readermanage();
			break;
		case 5:
			filemanage();
			break;
		default:
			cout << "1.存储并退出" << endl << "其他不退出" << endl;
			int decmd;
			cin >> decmd;
			if (decmd == 1)
			{
				db.save();
				flag = 0;
			}
		}
	}
	return 0;
}