#ifndef CUSER_H 
#define CUSER_H 

#include <string>
using namespace std;
class CUser
{
protected:

	int code;      //表示用户编号；

	string name;  //表示用户姓名

public:

	CUser();   // 默认构造函数

	CUser(int id, string na);   //构造函数，初始化用户信息

	void setcode(int n);      //用来设置用户编号

	int getcode();          //用来获取用户编号

	void setname(string na);  //用来设置用户姓名

	string  getname();        //用来获取用户姓名

	void show();           //用来显示用户的基本信息
};

#endif //CUSER_H