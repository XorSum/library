#ifndef CBOOK_H 
#define CBOOK_H 
#include <string>
using namespace std;
class CBook
{
private:
	int code;              //图书编号
	string name;     //图书名称
	bool Is_Stock;          //true为在架，false为借出
	bool Is_Existing;       //true为存在, false为删除
public:
	CBook(); //默认构造函数
	CBook(int co, string na);    //构造函数，初始化图书信息
	void setcode(int n);   //设置图书编号
	int getcode();    //获取图书编号
	void setname(string na);    //设置图书名称
	string getname();  //获取图书名称
	bool  get_Stock();  //获取图书是否在库信息
	void set_Stock(bool is);// 设置图书是否在库信息
	bool  get_Existing();//获取存在标志
	void set_Existing(bool is);//设置存在标志
	void show();				
};

#endif //CBOOK_H 