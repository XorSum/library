#include "DataBase.h"
#include<string>
DataBase::DataBase()
{
}

DataBase::~DataBase()
{
}

void DataBase::addbook(CBook book)
{
	bkarray.push_back(book);

}

int DataBase::findbook(string name)
{
	for (int i = 0; i < bkarray.size(); i++)
	{
		if (bkarray[i].getname() == name) return i;
	}
	return -1;
}

int DataBase::findbook(int code)
{
	for (int i = 0; i < bkarray.size(); i++)
	{
		if (bkarray[i].getcode() == code) return i;
	}
	return -1;
}

void DataBase::editbook(int subscript, CBook book)
{
	bkarray[subscript] = book;
}

void DataBase::delbook(int subscript)
{
	bkarray[subscript].set_Existing(false);
}

void DataBase::listbooks()
{
	for (int i = 0; i < bkarray.size(); i++)
	{
		if (bkarray[i].get_Existing())
			bkarray[i].show();
	}
}

void DataBase::addreader(CReader reader)
{
	rdarray.push_back(reader);
}

int DataBase::findreader(string name)
{
	for (int i = 0; i < rdarray.size(); i++)
	{
		if (rdarray[i].getname() == name) return i;
	}
	return -1;
}

int DataBase::findreader(int code)
{
	for (int i = 0; i < rdarray.size(); i++)
	{
		if (rdarray[i].getcode() == code) return i;
	}
	return -1;
}

int DataBase::findreader(CBook book)
{
	for (int i = 0; i < rdarray.size(); i++)
	{
		if (rdarray[i].getbrbook().getcode()== book.getcode()&& rdarray[i].getbrbook().getname() == book.getname()) return i;
	}
	return -1;
}

void DataBase::editreader(int subscript, CReader reader)
{
	rdarray[subscript] = reader;
}

void DataBase::delreader(int subscript)
{
	rdarray[subscript].set_Existing(false);
}

void DataBase::listreaders()
{
	for (int i = 0; i < rdarray.size(); i++)
	{
		if (rdarray[i].get_Existing()) rdarray[i].show();
	}
}

