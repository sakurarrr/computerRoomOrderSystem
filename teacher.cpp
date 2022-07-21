#include"teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher() {

}

//�в͹��죨��ţ� ������ ����
Teacher::Teacher(int empId, string name, string pwd) {
	//��ʼ������
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu() {
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------------------------------\n";
	cout << "\t\t|                                                        |\n";
	cout << "\t\t|                   1.�鿴����ԤԼ                       |\n";
	cout << "\t\t|                                                        |\n";
	cout << "\t\t|                   2.���ԤԼ                           |\n";
	cout << "\t\t|                                                        |\n";
	cout << "\t\t|                   0.ע����¼                           |\n";
	cout << "\t\t|                                                        |\n";
	cout << "\t\t ---------------------------------------------------------\n";
	cout << "��ѡ����Ĳ�����" << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; ++i) {
		cout << i + 1 << "��";

		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << "  ʱ��Σ� " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "  ѧ�ţ� " << of.m_orderData[i]["stuId"];
		cout << "  ������ " << of.m_orderData[i]["stuName"];
		cout << "  �����ţ� " << of.m_orderData[i]["roomId"];
		string status = "  ״̬��";
		if (of.m_orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ���";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "���ʧ��";
		}
		else {
			status += "ԤԼȡ����";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int> vec;
	int index = 0;
	for (int i = 0; i < of.m_Size; ++i) {
		if (of.m_orderData[i]["status"] == "1") {
			vec.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << "  ʱ��Σ� " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "  ѧ�ţ� " << of.m_orderData[i]["stuId"];
			cout << "  ������ " << of.m_orderData[i]["stuName"];
			cout << "  �����ţ� " << of.m_orderData[i]["roomId"];
			string status = "״̬�������";
			cout << status << endl;

		}
	}

	cout << "��������˵�ԤԼ��¼�� 0������" << endl;
	int select2 = 0;
	int ret = 0;//����ԤԼ�����¼
	while (true) {
		cin >> select2;
		if (select2 >= 0 && select2 <= vec.size()) {
			if (select2 == 0) { 
				break;
			}
			else {
				cout << "��������˵Ľ��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1) {
					//ͨ��
					of.m_orderData[vec[select2 - 1]]["status"] = "2";
				}
				else if (ret == 2) {
					//��ͨ��
					of.m_orderData[vec[select2 - 1]]["status"] = "-1";
				}
				of.updateOrder();//����ԤԼ��¼
				cout << "�����ϣ�" << endl;
				break;
			}
		}else{
			cout << "�����������������룡" << endl;

		}
	}
	system("pause");
	system("cls");
}