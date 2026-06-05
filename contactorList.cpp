#include "contactorList.h"

const string ContactorList::CONTACT_FILE = "contact.txt";

// getter系列
int ContactorList::getContactorListSize() const {
	return this->ContactorListSize;
}

// CRUD:增删改查

 // 新增联系人 O（1）
bool ContactorList::addContactor(Contactor* newone) {
	// 统一检查重名
	if (HaxiTable.count(newone->getRemark()) != 0) {
		delete newone;
		return false;
	}
	if (head == nullptr) {
		head = tail = newone;
	}
	else {
		tail->next = newone;
		tail = tail->next;
	}
	++this->ContactorListSize;
	HaxiTable[newone->getRemark()] = newone;
	return true;
}

// 删除联系人 O（n）
bool ContactorList::eraseContactor(const string& remark) {
	// 如果查不到联系人，返回false
	Contactor* person = getContactor(remark);
	if (person == nullptr) return false;
	// 如果联系人只有一个
	else if (head == tail) {
		delete person;
		--this->ContactorListSize;
		HaxiTable.erase(remark);
		head = tail = nullptr;
		return true;
	}
	// 如果删的是头节点
	else if (person == head) {
		head = head->next;
		--this->ContactorListSize;
		HaxiTable.erase(remark);
		delete person;
		return true;
	}
	Contactor* current = head;
	while (current->next != person) {
		current = current->next;
	}
	current->next = current->next->next;
	// 如果联系人在尾部
	if (tail == person) tail = current;
	--this->ContactorListSize;
	HaxiTable.erase(remark);
	delete person;
	return true;
}

// 返回联系人节点 O（1）
Contactor* ContactorList::getContactor(const string& remark) {
	if (HaxiTable.count(remark) == 0) return nullptr;
	return HaxiTable[remark];
}

// 配合panel面板
vector<Contactor*> ContactorList::getAll() {
	vector<Contactor*> ans;
	Contactor* current = head;
	while (current != nullptr) {
		ans.emplace_back(current);
		current = current->next;
	}
	return ans;
}

// 文件读写

// 保存到文件中
bool ContactorList::saveToFile() {
	ofstream fout(CONTACT_FILE);
	if (!fout.is_open()) {
		return false;
	}
	fout << ContactorListSize << '\n';
	Contactor* current = head;
	while (current != nullptr) {
		fout << current->getRemark() << '|';
		fout << current->getBirthday() << '|';
		fout << current->getGender() << '|';
		fout << current->getSignature() << '|';
		fout << current->getPhone() << '|';
		fout << current->getArea() << '|';
		fout << '\n';
		current = current->next;
	}
	fout.close();
	return true;
}

// 从文件中下载
bool ContactorList::loadFromFile() {
	ifstream fin(CONTACT_FILE);
	if (!fin.is_open()) {
		return false;
	}
	// 还原
	Contactor* current = head;
	while (current != nullptr) {
		Contactor* node = current;
		current = current->next;
		delete node;
	}
	head = tail = nullptr;
	this->ContactorListSize = 0;
	HaxiTable.clear();
	// 填数据
	if (!(fin >> ContactorListSize) || ContactorListSize < 0) {
		fin.close();
		return false;
	}
	fin.ignore();
	string s;
	vector<string> info;
	for (int i = 0; i < ContactorListSize; ++i) {
		getline(fin, s);
		info = Common::split(s, '|');
		current = new Contactor(info.at(0), info.at(1), info.at(2), info.at(3), info.at(4), info.at(5));
		addContactor(current);
	}
	fin.close();
	return true;
}

// 重写虚构函数
ContactorList::~ContactorList() {
	Contactor* current = head;
	while (current != nullptr) {
		Contactor* node = current;
		current = current->next;
		delete node;
	}
}