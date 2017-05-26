#include "CBookManager.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

CBookManager::CBookManager()
{
}


CBookManager::~CBookManager()
{
}

void CBookManager::addbook(CBook book)
{
	bkarray.push_back(book);
}

int CBookManager::findbook(string name)
{
	for (int i = 0; i < bkarray.size(); i++)
	{
		if (bkarray[i].getname() == name) return i;
	}
	return -1;
}

int CBookManager::findbook(int code)
{
	for (int i = 0; i < bkarray.size(); i++)
	{
		if (bkarray[i].getcode() == code && bkarray[i].get_Existing() == true)
		{
			if (bkarray[i].get_Stock() == true)
				return i;
			else return -2;
		}
	}
	return -1;
}

CBook CBookManager::getbook(int subscript)
{
	return bkarray[subscript];
}

void CBookManager::editbook(int subscript, CBook book)
{
	bkarray[subscript] = book;
}

void CBookManager::editbook(int subscript, int code)
{
	bkarray[subscript].setcode(code);
}

void CBookManager::editbook(int subscript, string name)
{
	bkarray[subscript].setname(name);
}

void CBookManager::editbook(int subscript, bool Is_Stock)
{
	bkarray[subscript].set_Stock(Is_Stock);
}

void CBookManager::delbook(int subscript)
{
	bkarray[subscript].set_Existing(false);
}

void CBookManager::listbooks()
{
	cout << "所有的图书：" << endl;
	for (int i = 0; i < bkarray.size(); i++)
	{
		if (bkarray[i].get_Existing())
			bkarray[i].show();
	}
}

void CBookManager::save(string filename)
{
	ofstream outfile(filename.c_str(), ios::binary);
	if (!outfile.is_open())
	{
		cout << "Error opening file";
		return;
	}
	int bksize = bkarray.size();
	outfile.write((char*)(&bksize), sizeof(bksize));
	for (int i = 0; i <bksize; i++)
		outfile.write((char*)(&bkarray[i]), sizeof(CBook));
	outfile.close();
}
void CBookManager::load(string filename)
{
	ifstream infile(filename.c_str(), ios::binary);
	if (!infile.is_open())
	{
		cout << "Error opening file";
		return;
	}
	bkarray.clear();
	int bksize;
	infile.read((char*)(&bksize), sizeof(bksize));
	bkarray.reserve(bksize * 2);
	CBook *bookarray = new CBook[bksize];
	for (int i = 0; i < bksize; i++)
	{
		infile.read((char*)(&bookarray[i]), sizeof(CBook));
		bkarray.push_back(bookarray[i]);
	}
	infile.close();
}