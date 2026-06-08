#pragma once
#include <unordered_map>
#include <fstream>
#include "eventNode.h"

using std::unordered_map;
using std::ofstream;
using std::ifstream;

class ReservationForm {
private:
	static const string RESERVATION_FILE;
	EventNode* head;
	EventNode* tail;
	int reservationFormSize;
	unordered_map<int, EventNode*> idFind;
	void linkAandB(EventNode* A, EventNode* B);
	void insertAafterB(EventNode* A, EventNode* B);
	void breakNode(EventNode* node);

public:
	ReservationForm();
	~ReservationForm();
	int getSize() const noexcept;
	void clear() noexcept;
	bool addEvent(EventNode* event) noexcept;
	bool eraseEvent(EventNode* event) noexcept;
	bool eraseEvenet(const int& eventId) noexcept;
	vector<Event> getAll() const noexcept;
	bool saveToFile() noexcept;
	bool loadFromFile() noexcept;
};