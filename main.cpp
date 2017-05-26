#include "CReader.h"
#include "CBook.h"
#include "CUser.h"
#include "CBookManager.h"
#include "CReaderManager.h"
#include <iostream>
CBookManager bookManager;
CReaderManager readerManager;
int landbook()
{
	string readerName, bookName;
	int readerSubscript, bookSubscript;
	cout << "请输入读者名称" << endl;
	cin >> readerName;
	readerSubscript = readerManager.findreader(readerName);
	if (readerSubscript == -1)
	{
		cout << "读者不存在" << endl;
		return 0;
	}
	cout << "请输入书籍名称" << endl;
	cin >> bookName;
	bookSubscript = bookManager.findbook(bookName);
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
	bookManager.editbook(bookSubscript, false);
	readerManager.editreader(readerSubscript, bookManager.getbook(bookSubscript));
	readerManager.editreader(readerSubscript, true);
	cout << "借书成功" << endl;
	return 0;
}
int returnbook()
{
	cout << "请输入读者名称" << endl;
	string readername;
	cin >> readername;
	int readersubscript = readerManager.findreader(readername);
	if (readersubscript == -1)
	{
		cout << "读者不存在" << endl;
		return 0;
	}
	CReader reader = readerManager.getreader(readersubscript);
	CBook book = reader.getbrbook();
	int booksubscript = bookManager.findbook(book.getname());
	if (booksubscript == -1)
	{
		cout << "书并不是本馆的" << endl;
		return 0;
	}
	bookManager.editbook(booksubscript, true);
	readerManager.editreader(readersubscript, false);
	return 0;
}

int bookcreate() 
{ 
	CBook book;
	int code;
	string name;
	cout << "请输入书号" << endl;
	cin >> code;
	cout << "请输入书名" << endl;
	cin >> name;
	book.setcode(code);
	book.setname(name);
	bookManager.addbook(book);
	return 0; 
}
int bookdelete() 
{ 
	cout << "请输入书名" << endl;
	string bookname;
	cin >> bookname;
	int booksubscript = bookManager.findbook(bookname);
	if (booksubscript == -1)
	{
		cout << "没有这本书" << endl;
		return 0;
	}
	bookManager.delbook(booksubscript);
	cout << "删除成功" << endl;
	return 0;
}
int bookedit() 
{ 
	cout << "请输入书名" << endl;
	string bookname;
	cin >> bookname;
	int booksubscript = bookManager.findbook(bookname);
	if (booksubscript == -1)
	{
		cout << "没有这本书" << endl;
		return 0;
	}
	int newbookcode;
	string newbookname;
	cout << "请输入新书名" << endl;
	cin >> newbookname;
	bookManager.editbook(booksubscript, newbookname);
	cout << "请输入新书号" << endl;
	cin >> newbookcode;
	bookManager.editbook(booksubscript, newbookcode);
	cout << "更改成功" << endl;
	return 0;
}
int bookfind() 
{ 
	cout << "1.按书名查找" << endl << "2.按书号查找" << "其他退出" << endl;
	int command;
	cin >> command;
	int booksubscript=-1;
	if (command == 1)
	{
		cout << "请输入书名" << endl;
		string bookname;
		cin >> bookname;
		booksubscript = bookManager.findbook(bookname);
	}
	else if (command == 2)
	{
		cout << "请输入书号" << endl;
		int bookcode;
		cin >> bookcode;
		booksubscript = bookManager.findbook(bookcode);
	}
	else
	{
		return 0;
	}
	if (booksubscript == -1)
	{
		cout << "没有这本书" << endl;
		return 0;
	}
	CBook book = bookManager.getbook(booksubscript);
	book.show();
	return 0; 
}
int booklist()
{
	bookManager.listbooks();
	return 0;
}
int bookmanage()
{
	cout << "1.增加图书" << endl;
	cout << "2.删除图书" << endl;
	cout << "3.更改图书" << endl;
	cout << "4.查找图书" << endl;
	cout << "5.显示图书" << endl;
	int command;
	cout << "请输入指令" << endl;
	cin >> command;
	switch (command)
	{
	case 1:
		bookcreate();
		break;
	case 2:
		bookdelete();
		break;
	case 3:
		bookedit();
		break;
	case 4:
		bookfind();
		break;
	case 5:
		booklist();
	default:
		return 0;
	}
	return 0;
}
int readercreate() 
{
	int code;
	string name;
	CReader reader;
	cout << "请输入编号" << endl;
	cin >> code;
	cout << "请输入姓名" << endl;
	cin >> name;
	reader.setcode(code);
	reader.setname(name);
	readerManager.addreader(reader);
	return 0;
}
int readerdelete() 
{ 
	cout << "请输入读者姓名" << endl;
	string readername;
	cin >> readername;
	int  readersubscript = readerManager.findreader(readername);
	if (readersubscript == -1)
	{
		cout << "没有这位读者" << endl;
		return 0;
	}
	readerManager.delreader(readersubscript);
	cout << "删除成功" << endl;
	return 0;
}
int readeredit() 
{ 
	cout << "请输入读者姓名" << endl;
	string readername;
	cin >> readername;
	int readersubscript = readerManager.findreader(readername);
	if (readersubscript == -1)
	{
		cout << "没有这位读者" << endl;
		return 0;
	}
	int newreadercode;
	string newreadername;
	cout << "请输入新读者姓名" << endl;
	cin >> newreadername;
	readerManager.editreader(readersubscript, newreadername);
	cout << "请输入新读者编号" << endl;
	cin >> newreadercode;
	readerManager.editreader(readersubscript, newreadercode);
	cout << "更改成功" << endl;
	return 0;
}
int readerfind()
{ 
	cout << "1.按书名查找" << endl << "2.按书号查找" << "其他退出" << endl;
	int command;
	cin >> command;
	int readersubscript = -1;
	if (command == 1)
	{
		cout << "请输入书名" << endl;
		string readername;
		cin >> readername;
		readersubscript = readerManager.findreader(readername);
	}
	else if (command == 2)
	{
		cout << "请输入书号" << endl;
		int readercode;
		cin >> readercode;
		readersubscript = readerManager.findreader(readercode);
	}
	else
	{
		return 0;
	}
	if (readersubscript == -1)
	{
		cout << "没有这本书" << endl;
		return 0;
	}
	CReader reader = readerManager.getreader(readersubscript);
	reader.show();
	return 0;
}
int readerlist()
{
	readerManager.listreaders();
	return 0;
}
int readermanage()
{
	cout << "1.增加读者" << endl;
	cout << "2.删除读者" << endl;
	cout << "3.更改读者" << endl;
	cout << "4.查找读者" << endl;
	cout << "5.显示读者" << endl;
	int command;
	cout << "请输入指令" << endl;
	cin >> command;
	switch (command)
	{
	case 1:
		readercreate();
		break;
	case 2:
		readerdelete();
		break;
	case 3:
		readeredit();
		break;
	case 4:
		readerfind();
	case 5:
		readerlist();
		break;
	default:
		return 0;
	}
	return 0;
}
int filemanage()
{
	cout << "1.文件存储" << endl << "2.文件读取" << endl;
	int command;
	cin >> command;
	if (command == 1)
	{
		readerManager.save();
		bookManager.save();
		cout << "已存储在books.db和readers.db中" << endl;
		return 0;
	}
	else if (command == 2)
	{
		readerManager.load();
		bookManager.load();
		cout << "文件已读取" << endl;
		bookManager.listbooks();
		cout << endl;
		readerManager.listreaders();
		return 0;
	}
	else
	{
		cout << "文件未操作" << endl;
		return 1;
	}
	return 0;
}
int main()
{
	cout << "欢迎使用图书馆管理系统" << endl;
	bool flag = true;
	while (flag)
	{
		cout << "1.借书" << endl;
		cout << "2.还书" << endl;
		cout << "3.图书管理" << endl;
		cout << "4.读者管理" << endl;
		cout << "5.文件存储" << endl;
		cout << "其他退出" << endl;
		int command;
		cout << "请输入指令" << endl;
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
			flag = false;
		}
	}
	bookManager.save();
	readerManager.save();
	return 0;
}