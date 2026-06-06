#pragma once
#include "event.h"

using std::stoi;

// 把Event类变成EventNode类来用
class EventNode {
private:
	Event data;
	int start, end;
public:
	EventNode* prev;
	EventNode* next;
	EventNode() : start(0), end(0), prev(nullptr), next(nullptr) {}
	EventNode(string theme, string description, string remark, string startTime, string duration, vector<Contactor*> linkContactors) :
		data(theme, description, remark, startTime, duration, linkContactors), prev(nullptr), next(nullptr) {
		vector<string> realTime = Common::split(data.getStartTime(), '-');
		this->start = stoi(realTime.at(0)) * 60 + stoi(realTime.at(1));
		this->end = this->start + stoi(data.getDuration());
	}
	Event getData() const noexcept { return this->data; }
	int getStart() const noexcept { return this->start; }
	int getId() const noexcept { return data.getId(); }
	string getTheme() const noexcept { return data.getTheme(); }
	string getDescription() const noexcept { return data.getDescription(); }
	string getRemark() const noexcept { return data.getRemark(); }
	string getStartTime() const noexcept { return data.getStartTime(); }
	string getDuration() const noexcept { return data.getDuration(); }
	void setTheme(const string& theme) noexcept { data.setTheme(theme); }
	void setDescription(const string& description) noexcept { data.setDescription(description); }
	void setRemark(const string& remark) noexcept { data.setRemark(remark); }
	void setStartTime(const string& startTime) noexcept {
		originalHelper(startTime, data.getDuration());
	}
	void setDuration(const string& duration) noexcept {
		originalHelper(data.getStartTime(), duration);
	}
	vector<Contactor*>& getLinkContactors() noexcept { return data.getLinkContactors(); }
	void originalHelper(const string& startTime, const string& duration) noexcept{
		data.setStartTime(startTime);
		data.setDuration(duration);
		vector<string> realTime = Common::split(startTime, '-');
		this->start = stoi(realTime.at(0)) * 60 + stoi(realTime.at(1));
		this->end = this->start + stoi(duration);
	}
};