#ifndef  DATABASE_H
#define  DATABASE_H
#include <vector>
#include <string>
#include "CBook.h"
#include "CReader.h"
using namespace std;
class DataBase
{
private:
	vector <CBook> bkarray;  //存储图书信息
	vector <CReader> rdarray;// 存储读者信息
public:
	DataBase();
	~DataBase();
	void addbook(CBook book);    //添加图书
	int findbook(string name);  //查找图书
	int findbook(int code);  //查找图书
	void editbook(int subscript,CBook book);//编辑图书
	void delbook(int subscript);   //  删除图书
	void listbooks();  //显示全部图书
	void addreader(CReader reader);          //添加读者
	int findreader(string name); //查找读者
	int findreader(int code); //查找读者
	int findreader(CBook book); //查找读者
	void editreader(int subscript,CReader reader); //编辑读者信息
	void delreader(int subscript);          //删除读者，读者如果借书要还书后才能删除
	void listreaders();           //显示所有读者
};

#endif // DATABASE_H