#ifndef CREADERMANAGER_H
#define CREADERMANAGER_H
#include <vector>
#include <string>
#include "CReader.h"
using namespace std;
class CReaderManager
{
private:
	vector <CReader> rdarray;// 存储读者信息
public:
	CReaderManager();
	~CReaderManager();
	CReader getreader(int subscript);
	void addreader(CReader reader);          //添加读者
	int findreader(string name); //查找读者
	int findreader(int code); //查找读者
	int findreader(CBook book); //查找读者
	void editreader(int subscript, CReader reader); //编辑读者信息
	void editreader(int subscript, string name); //编辑读者信息
	void editreader(int subscript, int code); //编辑读者信息
	void editreader(int subscript, CBook book); //编辑读者信息
	void editreader(int subscript, bool Is_Borrowing); //编辑读者信息
	void delreader(int subscript);          //删除读者，读者如果借书要还书后才能删除
	void listreaders();           //显示所有读者
	void save(string filename = "readers.db"); // 保存到文件
	void load(string filename = "readers.db"); // 从文件读取
};

#endif //CREADERMANAGER_H