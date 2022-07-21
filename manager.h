#pragma once
#include <iostream>
#include "Identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"

using namespace std;

//管理员类
class Manager : public Identity
{
public:
	//默认构造
	Manager();

	//有餐构造（编号， 姓名， 密码
	Manager(string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//初始化容器
	void initVector();

	//检测重复 参数（传入ID， 传入类型）
	bool checkRepeat(int id, int type);

	//学生容器
	vector<Student> vStu;

	//老师容器
	vector<Teacher> vTea;

	//机房容器
	vector<ComputerRoom> vCom;
};