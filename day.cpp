#include "day.h"

// 操作相关函数：不管更新，不管检测边界

 // 把A和B节点顺序连接
void Day::linkAandB(EventNode* A, EventNode* B) {
	A->next = B;
	B->prev = A;
}

// 把A节点插入到B节点后
void Day::insertAafterB(EventNode* A, EventNode* B) {
	// 获取B的下一个节点
	EventNode* Bnext = B->next;
	// 连接
	linkAandB(B, A);
	linkAandB(A, Bnext);
}

// 只负责把node节点从链表中移除
void Day::breakNode(EventNode* node) {
	EventNode* theNext = node->next;
	EventNode* thePrev = node->prev;
	linkAandB(thePrev, theNext);
}

// 构造函数
Day::Day() {
	head = new EventNode();
	head->originalHelper("00-00", "0");
	tail = new EventNode();
	tail->originalHelper("24-01", "0");
	linkAandB(head, tail);
	this->numOfEvent = 0;
}
// 析构函数
Day::~Day() {
	EventNode* current = head;
	while (current != nullptr) {
		EventNode* node = current;
		current = current->next;
		delete node;
	}
}

// 添加事件
bool Day::addEvent(EventNode* event) noexcept {
	// 插入合法性：id不能相同
	if (idFind.count(event->getId()) != 0) {
		return false;
	}
	int currentStart = event->getStart();
	EventNode* current = head;
	while (current != tail && !(current->getStart() <= currentStart && current->next->getStart() > currentStart)) {
		current = current->next;
	}
	// 插入合法性：时间不合法
	if (current == tail) return false;
	// 全部合法可插入
	insertAafterB(event, current);
	// 更新
	++this->numOfEvent;
	idFind[event->getId()] = event;
	// 返回
	return true;
}

// ID查找事件
EventNode* Day::findEventById(const int& id) const noexcept {
	if (idFind.count(id) == 0) {
		return nullptr;
	}
	return idFind.at(id);
}

// 删除事件
bool Day::eraseEvent(EventNode* event) noexcept {
	if (findEventById(event->getId()) == nullptr) return false;
	breakNode(event);
	--this->numOfEvent;
	idFind.erase(event->getId());
	delete event;
	return true;
}
bool Day::eraseEvent(const int& id) noexcept {
	EventNode* event = findEventById(id);
	if (event == nullptr) return false;
	breakNode(event);
	--this->numOfEvent;
	idFind.erase(id);
	delete event;
	return true;
}


// 获取当天事件数
int Day::getNumOfEvent()const noexcept {
	return this->numOfEvent;
}

// 顺序返回该天所有事件：配合面板
vector<Event> Day::getAllEvent() const noexcept {
	vector<Event> ans;
	EventNode* current = head->next;
	while (current != tail) {
		ans.emplace_back(current->getData());
		current = current->next;
	}
	return ans;
}