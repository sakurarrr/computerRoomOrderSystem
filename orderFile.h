#pragma once
#include<iostream>
#include<map>
#include"globalFile.h"
#include<fstream>

using namespace std;

class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼������   ��¼������    �����¼����Ϣ
	map<int, map<string, string>> m_orderData;

	//ԤԼ��¼����
	int m_Size;
};