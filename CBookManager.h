#ifndef CBOOKMANAGER_H
#define CBOOKMANAGER_H
#include <vector>
#include <string>
#include "CBook.h"
using namespace std;
class CBookManager
{
private:
	vector <CBook> bkarray;  //存储图书信息
public:
	CBookManager();
	~CBookManager();
	void addbook(CBook book);    //添加图书
	int findbook(string name);  //查找图书
	int findbook(int code);  //查找图书
	CBook getbook(int subscript);
	void editbook(int subscript, CBook book);//编辑图书
	void editbook(int subscript, int code);//编辑图书
	void editbook(int subscript, string name);//编辑图书
	void editbook(int subscript, bool Is_Stock);//编辑图书
	void delbook(int subscript);   //删除图书
	void listbooks();  //显示全部图书
	void save(string filename = "books.db"); // 保存到文件
	void load(string filename = "books.db"); // 从文件读取
};

#endif //CBOOKMANAGER_H
