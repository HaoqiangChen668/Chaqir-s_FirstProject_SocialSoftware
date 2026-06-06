#pragma once
#include "contactor.h"
#include <unordered_map>
#include <fstream>

using std::unordered_map;
using std::ofstream;
using std::ifstream;

class ContactorList {

private:
	static const string CONTACT_FILE; // 通讯录存储路径
	Contactor* head; // 通讯录头节点
	Contactor* tail; // 通讯录尾节点
	int ContactorListSize; // 通讯录当前大小
	unordered_map<string, Contactor*> HaxiTable; // 根据备注查找节点 

public:
	// 构造函数
	ContactorList() {
		head = tail = nullptr;
		this->ContactorListSize = 0;
	}

	// getter系列
	int getContactorListSize() const noexcept;

	// CRUD:增删改查
	bool addContactor(Contactor* newone) noexcept; // 新增联系人 O（1）
	bool eraseContactor(const string& remark) noexcept; // 删除联系人 O（n）
	Contactor* getContactor(const string& remark) noexcept; // 返回联系人节点 O（1）

	// 配合panel面板
	vector<Contactor*> getAll() noexcept;

	// 文件读写
	bool saveToFile() noexcept;
	bool loadFromFile() noexcept;

	// 重写虚构函数
	~ContactorList() noexcept;

};