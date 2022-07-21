#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//进入学生子菜单界面
void studentMenu(Identity*& student) {
	while (true) {
		//调用学生子菜单
		student->operMenu();

		//将父类指针转化为子类指针，调用子类里其他特有接口
		Student* stu = (Student*)student;

		int select = 0;//接收用户选择
		cin >> select;

		if (select == 1) {
			//申请预约
			cout << "申请预约" << endl;
			stu->applyOrder();

		}
		else if (select == 2) {
			//查看自身预约
			cout << "查看自身预约" << endl;
			stu->showMyOrder();

		}
		else if (select == 3) {
			//查看所有人预约
			cout << "查看所有人预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) {
			//取消预约
			cout << "取消预约" << endl;
			stu->cancelOrder();
		}
		else {
			//注销
			delete student;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}	
 }

//进入教室子菜单界面
void teacherMenu(Identity*& teacher) {
	while (true) {
		//调用子菜单界面
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1) {
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2) {
			//审核预约			
			tea->validOrder();
		}
		else {
			//注销登录
			delete teacher;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员子菜单界面
void managerMenu(Identity*& manager) {
	while (true) {
		//调用管理员的子菜单
		manager->operMenu();

		//将父类指针转化为子类指针，调用子类里其他特有接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接收用户的选择
		cin >> select;
		if (select == 1) { //添加账号
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) { //查看账号
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) { //查看机房信息
			cout << "查看机房信息" << endl;
			man->showComputer();
		}
		else if (select == 4) { //清空预约
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else { //注销
			delete manager;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能（操作文件名， 操作身份类型
void LoginIn(string fileName, int type) {
	//父类指针， 用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接收用户信息
	int id = 0;
	string name;//姓名
	string pwd;//密码
	
	//判断身份
	if (type == 1) {
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	if (type == 1) {
		//学生身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//与用户输入信息进行对比
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生验证通过！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//教师身份认证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//与用户输入信息进行对比
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "教师验证通过！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员身份认证
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd) {
			//与用户输入信息进行对比
			if ( fName == name && fPwd == pwd) {
				cout << "管理员验证通过！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份的子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");

	return;
}
int main() {
	int select = 0; //接收用户的选择

	while (true) {
		cout << "==================== 欢迎来到机房预约系统 ====================" << endl;
		cout << endl << "请输入你的身份" << endl;
		cout << "\t\t ---------------------------------------------------------\n";
		cout << "\t\t|                                                        |\n";
		cout << "\t\t|                   1.学生代表                           |\n";
		cout << "\t\t|                                                        |\n";
		cout << "\t\t|                   2.老    师                           |\n";
		cout << "\t\t|                                                        |\n";
		cout << "\t\t|                   3.管 理 员                           |\n";
		cout << "\t\t|                                                        |\n";
		cout << "\t\t|                   0.退    出                           |\n";
		cout << "\t\t|                                                        |\n";
		cout << "\t\t ---------------------------------------------------------\n";
		cout << "请输入你的选择 ：";

		cin >> select;

		switch (select)
		{
		case 1: //学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: //管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}