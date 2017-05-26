#include "CReaderManager.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


CReaderManager::CReaderManager()
{
}


CReaderManager::~CReaderManager()
{
}

CReader CReaderManager::getreader(int subscript)
{
	return rdarray[subscript];
}
void CReaderManager::addreader(CReader reader)
{
	rdarray.push_back(reader);
}

int CReaderManager::findreader(string name)
{
	for (int i = 0; i < rdarray.size(); i++)
	{
		if (rdarray[i].getname() == name) return i;
	}
	return -1;
}

int CReaderManager::findreader(int code)
{
	for (int i = 0; i < rdarray.size(); i++)
	{
		if (rdarray[i].getcode() == code) return i;
	}
	return -1;
}

int CReaderManager::findreader(CBook book)
{
	for (int i = 0; i < rdarray.size(); i++)
	{
		if (rdarray[i].getbrbook().getcode() == book.getcode() && rdarray[i].getbrbook().getname() == book.getname()) return i;
	}
	return -1;
}

void CReaderManager::editreader(int subscript, CReader reader)
{
	rdarray[subscript] = reader;
}

void CReaderManager::editreader(int subscript, string name)
{
	rdarray[subscript].setname(name);
}

void CReaderManager::editreader(int subscript, int code)
{
	rdarray[subscript].setcode(code);
}

void CReaderManager::editreader(int subscript, CBook book)
{
	rdarray[subscript].setbrbook(book);
}

void CReaderManager::editreader(int subscript, bool Is_Borrowing)
{
	rdarray[subscript].set_Borrowing(Is_Borrowing);
}

void CReaderManager::delreader(int subscript)
{
	rdarray[subscript].set_Existing(false);
}

void CReaderManager::listreaders()
{
	cout << "所有的读者：" << endl;
	for (int i = 0; i < rdarray.size(); i++)
	{
		if (rdarray[i].get_Existing()) rdarray[i].show();
	}
}

void CReaderManager::save(string filename)
{
	ofstream outfile(filename.c_str(), ios::binary);
	if (!outfile.is_open())
	{
		cout << "Error opening file";
		return;
	}
	int rdsize = rdarray.size();
	outfile.write((char*)(&rdsize), sizeof(rdsize));
	for (int i = 0; i < rdsize; i++)
		outfile.write((char*)(&rdarray[i]), sizeof(CReader));
	outfile.close();
}
void CReaderManager::load(string filename)
{
	ifstream infile(filename.c_str(), ios::binary);
	if (!infile.is_open())
	{
		cout << "Error opening file";
		return;
	}
	rdarray.clear();
	int rdsize;
	infile.read((char*)(&rdsize), sizeof(rdsize));
	rdarray.reserve(rdsize * 2);
	CReader * readerarray = new CReader[rdsize];
	for (int i = 0; i < rdsize; i++)
	{
		infile.read((char*)(&readerarray[i]), sizeof(CReader));
		rdarray.push_back(readerarray[i]);
	}
	infile.close();
}