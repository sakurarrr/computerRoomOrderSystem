#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include<string>
#include"orderFile.h"
#include<vector>

//��ʦ��
class Teacher : public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�в͹��죨��ţ� ������ ����
	Teacher(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʦ���
	int m_EmpId;
};