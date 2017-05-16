#ifndef CBOOKMANAGER_H
#define CBOOKMANAGER_H
#include "CBook.h"
class CBookManager
{
private:

	CBook btarray[50];               //图书集合

	int top;                         //当前数组中存储的图书数量

public:

	CBookManager();

	~CBookManager();

	void addbooks();    //添加图书

	int findbooks(int suffix);  //查找图书，这个函数用于借书还书操作

	int findbooks();  //查找图书，用于图书维护操作

	void editbooks();     //编辑图书

	void delbooks();   //  删除图书

	void listbooks();  //显示全部图书
};
#endif //CBOOKMANAGER_H