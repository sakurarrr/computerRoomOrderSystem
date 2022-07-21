#include"manager.h"


//默认构造
Manager::Manager() {

}

//有餐构造（编号， 姓名， 密码
Manager::Manager(string name, string pwd) {
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器  获取所有文件中学生和老师的信息
	this->initVector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房数量为：" << vCom.size()<< endl;
}

//菜单界面
void Manager::operMenu() {
	cout << "欢迎管理员："<< this->m_Name<<"登录！" << endl;
	cout << "\t\t ---------------------------------------------------------\n";
	cout << "\t\t|                                                        |\n";
	cout << "\t\t|                   1.添加账号                           |\n";
	cout << "\t\t|                                                        |\n";
	cout << "\t\t|                   2.查看账号                           |\n";
	cout << "\t\t|                                                        |\n";
	cout << "\t\t|                   3.查看机房                           |\n";
	cout << "\t\t|                                                        |\n";
	cout << "\t\t|                   4.清空预约                           |\n";
	cout << "\t\t|                                                        |\n";
	cout << "\t\t|                   0.注销登录                           |\n";
	cout << "\t\t|                                                        |\n";
	cout << "\t\t ---------------------------------------------------------\n";
	cout << "请选择你的操作：" << endl;
}

//添加账号
void Manager::addPerson() {
	cout << "请输入添加账号的类型" << endl;//提示语句
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	
	string fileName;//操作文件名
	string tip;//提示ID号
	string errorTip;
	ofstream ofs;//文件操作对象

	int select = 0;//接收用户的选项
	cin >> select;

	if (select == 1) {
		//添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "输入的学号重复!";
	}
	else if(select == 2) {
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "输入的职工号重复!";
	}

	ofs.open(fileName, ios::out | ios::app);

	int id;//学号？职工号
	string name;
	string pwd;

	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}
	
	//cin >> id;
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	this->initVector();//重新初始化容器

	system("pause");
	system("cls");

	ofs.close();
}

//输出学生账号信息
void printStudent(Student& s) {
	cout << "学号:" << s.m_Id <<"  " << "姓名" << s.m_Name << "  " << "密码：" << s.m_Pwd << endl;
}

//输出老师账号信息
void printTeacher(Teacher& t) {
	cout << "职工号:" <<t.m_EmpId << "  " << "姓名" << t.m_Name << "  " << "密码：" << t.m_Pwd << endl;
}
//查看账号
void Manager::showPerson() {
	cout << "请选择查看内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	int select = 0;//接收用户选择
	cin >> select;
	if (select == 1) {
		//查看学生
		cout << "查看学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);

	}
	else {
		cout << "查看老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer() {
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); ++it) {
		cout << "机房编号：" << it->m_ComId << "  机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector() {
	//读取信息  
	vStu.clear();
	vTea.clear();//确保容器清空状态
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "读取文件失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "当前学生数量" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "读取文件失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "当前老师数量" << vTea.size() << endl;
	ifs.close();
}

//检测重复 参数（传入ID， 传入类型
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		//检测学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_Id) return true;
		}
	}
	else if (type == 2) {
		//检测老师
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_EmpId) return true;
		}
	}
	return false;
}