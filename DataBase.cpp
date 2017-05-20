#include "CBook.h"
#include "CUser.h"
#include "CReader.h"
#include "DataBase.h"
#include<string>
#include <fstream>  
#include <iostream>
#include <vector>

using namespace std;
DataBase::DataBase()
{
	bkarray.clear();
	rdarray.clear();
}

DataBase::~DataBase()
{
	bkarray.clear();
	rdarray.clear();
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

void DataBase::save(string filename)
{
	ofstream outfile(filename.c_str(),ios::binary);
	int bksize = bkarray.size();
	outfile.write((char*)(&bksize), sizeof(bksize));
	for (int i = 0; i <bksize; i++)
		outfile.write((char*)(&bkarray[i]), sizeof(CBook));
	int rdsize = rdarray.size();
	outfile.write((char*)(&rdsize), sizeof(rdsize));
	for (int i = 0; i < rdsize; i++)
		outfile.write((char*)(&rdarray[i]), sizeof(CReader));
	outfile.close();
}
void DataBase::load(string filename)
{
	ifstream infile(filename.c_str(), ios::binary);
	bkarray.clear();
	int bksize;
	CBook book;
	infile.read((char*)(&bksize), sizeof(bksize));
	bkarray.reserve(bksize * 2);
	for (int i = 0; i < bksize; i++)
	{
		infile.read((char*)(&book), sizeof(CBook));;
		bkarray.push_back(book);
	}
	rdarray.clear();
	int rdsize;
	CReader reader;
	infile.read((char*)(&rdsize), sizeof(rdsize));
	rdarray.reserve(rdsize * 2);
	for (int i = 0; i < rdsize; i++)
	{
		infile.read((char*)(&reader), sizeof(CReader));
		rdarray.push_back(reader);
	}
	infile.close();
	listbooks();
	listreaders();
/*
	cout << "qqqwwweee" << endl;
	bkarray.clear();
	rdarray.clear();
	CReader reader;
	rdarray.push_back(reader);
*/
}


