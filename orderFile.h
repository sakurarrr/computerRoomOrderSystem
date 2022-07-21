#pragma once
#include<iostream>
#include<map>
#include"globalFile.h"
#include<fstream>

using namespace std;

class OrderFile
{
public:
	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

	//记录的容器   记录的条数    具体记录的信息
	map<int, map<string, string>> m_orderData;

	//预约记录条数
	int m_Size;
};