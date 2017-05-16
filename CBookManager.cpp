#include "CBookManager.h"
#include <iostream>

CBookManager::CBookManager()
{
	top = 0;
}

CBookManager::~CBookManager()
{

}

void CBookManager::addbooks()
{
	btarray[top].set_Existing(true);
	btarray[top].set_Stock(true);
	top++;
}

int CBookManager::findbooks(int suffix)
{
	bool isfind = 0;
	for (int i = 0; i < top; i++)
	{
		if (btarray[i].getcode() == suffix)
		{
			isfind = i;
		}
	}
	return isfind;
}

int CBookManager::findbooks()
{
	return 0;
}

void CBookManager::editbooks()
{
	
}

void CBookManager::delbooks()
{

}

void CBookManager::listbooks()
{
	for (int i = 0; i < top; i++)
	{
		if (btarray[i].get_Stock() == true)
			std::cout << btarray[i].getcode() << " " << btarray[i].getname() << std::endl;
	}
}
