#ifndef CREADER_H 
#define CREADER_H 
#include "CBook.h"
#include "CUser.h"
using namespace std;
class CReader: public CUser
{
private:

	bool Is_Existing;  //true存在，false删除

	bool Is_Borrowing;  //true借过书，false没有借书

	CBook brbook;     //表示读者所借的图书

public:

	CReader();               //默认的构造函数

	CReader(int id, string na);   //构造函数，初始化读者信息

	bool get_Existing();        //用来获取删除标志

	void set_Existing(bool);     //用来设置删除标志

	bool get_Borrowing();      //用来获取读者借阅情况

	void set_Borrowing(bool);   //用来设置读者借阅情况

	void setbrbook(CBook bt);  //用来记录读者结束信息

	CBook getbrbook();		//用来获取读者结束信息

	void show();			//重写基类成员，显示读者的基本信息情况和借书情况
};

#endif //CREADER_H 