#pragma once
#include "eventNode.h"
#include <unordered_map>

using std::unordered_map;

class Day {
private:
	// 头尾节点是哨兵节点，没有具体意义
	EventNode* head;
	EventNode* tail;
	int numOfEvent;
	unordered_map<int, EventNode*> idFind;
	// 操作相关函数：不管更新，不管检测边界
	void linkAandB(EventNode* A, EventNode* B); // 把A和B节点顺序连接
	void insertAafterB(EventNode* A, EventNode* B); // 把A节点插入到B节点后
	void breakNode(EventNode* node); // 只负责把node节点从链表中移除
public:

	// 构造函数
	Day();

	// 析构函数
	~Day();

	// 添加事件
	bool addEvent(EventNode* event) noexcept;

	// ID查找事件
	EventNode* findEventById(const int& id) const noexcept;

	// 删除事件
	bool eraseEvent(EventNode* event) noexcept;
	bool eraseEvent(const int& id) noexcept;

	// 获取当天事件数
	int getNumOfEvent()const noexcept;

	// 顺序返回该天所有事件：配合面板
	vector<Event> getAllEvent() const noexcept;

	// 清空所有事件
	void clear() noexcept;
};
