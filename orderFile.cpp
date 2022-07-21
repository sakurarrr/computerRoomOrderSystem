#include"orderFile.h"

//构造函数
OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->m_Size = 0;//预约记录的条数

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
		string key;
		string value;
		map<string, string> m;

		int pos = date.find(":");//截取日期
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size());

			m.insert(make_pair(key, value));
		}
		
		pos = interval.find(":");//截取时间段
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size());

			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");//截取学生号
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size());

			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");//截取学生姓名
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size());

			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");//截取教室号
		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size());

			m.insert(make_pair(key, value));
		}

		pos = status.find(":");//截取状态
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size());

			m.insert(make_pair(key, value));
		}

		//将小 map 放入到大 map 中
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

	//测试最大容器
	/*for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); ++it) {
		cout << "条数为：" << it->first << "  value = " << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); ++mit) {
			cout << "   key = " << mit->first << "   value = " << mit->second;
		}
		cout << endl;

	}*/
}

//更新预约记录
void OrderFile::updateOrder() {
	if (this->m_Size == 0) {
		return;//预约记录为0
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; ++i) {
		ofs << "date:" << this->m_orderData[i]["date"] << "  ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << "  ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << "  ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << "  ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << "  ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;

	}
	ofs.close();
		
}