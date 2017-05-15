#ifndef CREADERMANAGER_H 
#define CREADERMANAGER_H 
#include "CReader.h"

class CReaderManager
{
private:

	CReader rdarray[50];// 存储读者信息的集合

	int top;      //当前数组中存储的读者数量

public:

	CReaderManager();  // 构造函数

	~CReaderManager();   //析构函数

	void addreaders();          //添加读者

	int findreaders(int suffix);     //查找读者，这个函数用于借书还书操作。          

	int findreaders();            //查找读者，这个函数用于读者维护操作

	void editreaders();          //编辑读者信息

	void delreaders();          //删除读者，读者如果借书要还书后才能删除

	void listreaders();           //显示所有读者
};

#endif //CREADERMANAGER_H 