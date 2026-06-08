#include "ReservationForm.h"

const string ReservationForm::RESERVATION_FILE = "reservation.txt";

// 操作相关函数：不管更新，不管检测边界

 // 把A和B节点顺序连接
void ReservationForm::linkAandB(EventNode* A, EventNode* B) {
	A->next = B;
	B->prev = A;
}

// 把A节点插入到B节点后
void ReservationForm::insertAafterB(EventNode* A, EventNode* B) {
	// 获取B的下一个节点
	EventNode* Bnext = B->next;
	// 连接
	linkAandB(B, A);
	linkAandB(A, Bnext);
}

// 只负责把node节点从链表中移除
void ReservationForm::breakNode(EventNode* node) {
	EventNode* theNext = node->next;
	EventNode* thePrev = node->prev;
	linkAandB(thePrev, theNext);
}

ReservationForm::ReservationForm() {
	head = new EventNode();
	tail = new EventNode();
	linkAandB(head, tail);
	this->reservationFormSize = 0;
}


ReservationForm::~ReservationForm() {
	clear();
	delete head;
	delete tail;
}


int ReservationForm::getSize() const noexcept {
	return this->reservationFormSize;
}


void ReservationForm::clear() noexcept {
	EventNode* current = head->next;
	while (current != tail) {
		EventNode* node = current;
		current = current->next;
		delete node;
	}
	idFind.clear();
	this->reservationFormSize = 0;
}


bool ReservationForm::addEvent(EventNode* event) noexcept {
	if (event == nullptr) return false;
	if (idFind.count(event->getId()) != 0) return false;
	insertAafterB(event, tail->prev);
	++this->reservationFormSize;
	idFind[event->getId()] = event;
	return true;
}


bool ReservationForm::eraseEvent(EventNode* event) noexcept {
	if (event == nullptr) return false;
	if (idFind.count(event->getId()) == 0) return false;
	breakNode(event);
	--this->reservationFormSize;
	idFind.erase(event->getId());
	delete event;
	return true;
}


bool ReservationForm::eraseEvenet(const int& eventId) noexcept {
	if (idFind.count(eventId) == 0) return false;
	breakNode(idFind[eventId]);
	--this->reservationFormSize;
	delete idFind[eventId];
	idFind.erase(eventId);
	return true;
}


vector<Event> ReservationForm::getAll() const noexcept {
	EventNode* current = head->next;
	vector<Event> ans;
	while (current != tail) {
		ans.emplace_back(current->getData());
		current = current->next;
	}
	return ans;
}


bool ReservationForm::saveToFile() noexcept {
	ofstream fout(RESERVATION_FILE);
	if (!fout.is_open()) return false;

	fout << this->reservationFormSize << '\n';
	EventNode* current = head->next;
	while (current != tail) {
		fout << current->getTheme() << '|';
		fout << current->getDescription() << '|';
		fout << current->getRemark() << '|';
		fout << current->getStartTime() << '|';
		fout << current->getDuration() << '|' << '\n';
		vector<Contactor*> lc = current->getLinkContactors();
		fout << lc.size() << '\n';
		for (Contactor* p : lc) {
			fout << p->getRemark() << '|';
			fout << p->getBirthday() << '|';
			fout << p->getGender() << '|';
			fout << p->getSignature() << '|';
			fout << p->getPhone() << '|';
			fout << p->getArea() << '|' << '\n';
		}
	}

	fout.close();
	return true;
}


bool ReservationForm::loadFromFile() noexcept {
	ifstream fin(RESERVATION_FILE);
	if (!fin.is_open()) return false;
	clear();

	fin >> this->reservationFormSize; fin.ignore();
	for (int i = 0; i < getSize(); ++i) {
		string s;
		getline(fin, s);
		vector<string> ss = Common::split(s, '|');
		vector<Contactor*> lc;
		int lc_size;
		fin >> lc_size; fin.ignore();
		for (int j = 0; j < lc_size; ++j) {
			string lc_s;
			getline(fin, lc_s);
			vector<string>lc_ss = Common::split(lc_s, '|');
			Contactor* contactor = new Contactor(lc_ss.at(0), lc_ss.at(1), lc_ss.at(2), lc_ss.at(3), lc_ss.at(4), lc_ss.at(5));
			lc.emplace_back(contactor);
		}
		EventNode* event = new EventNode(ss.at(0), ss.at(1), ss.at(2), ss.at(3), ss.at(4), lc);
		addEvent(event);
	}

	fin.close();
	return true;
}