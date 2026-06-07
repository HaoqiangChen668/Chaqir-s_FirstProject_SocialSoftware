#pragma once
#include "common.h"
#include "contactor.h"

class Event {
private:
	static int cntOfId;
	int id;
	string theme; // 主题
	string description; // 描述
	string remark; // 备注
	string startTime; // 开始时间（16-00）
	string duration; // 持续时间（90）min
	vector<Contactor*> linkContactors; // 关联的联系人
public:
	Event() :theme("空主题"), description("空描述"), remark("空备注") {
		startTime = duration = "empty";
		linkContactors.clear();
		id = cntOfId++;
	}
	Event(string theme, string description, string remark, string startTime, string duration, vector<Contactor*> linkContactors) :
		theme(theme), description(description), remark(remark), startTime(startTime), duration(duration), linkContactors(linkContactors) {
		id = cntOfId++;
	}
	~Event();
	int getId()const noexcept { return this->id; }
	string getTheme() const noexcept { return this->theme; }
	string getDescription() const noexcept { return this->description; }
	string getRemark() const noexcept { return this->remark; }
	string getStartTime() const noexcept { return this->startTime; }
	string getDuration() const noexcept { return this->duration; }
	void setTheme(const string& theme) noexcept { this->theme = theme; }
	void setDescription(const string& description) noexcept { this->description = description; }
	void setRemark(const string& remark) noexcept { this->remark = remark; }
	void setStartTime(const string& startTime) noexcept { this->startTime = startTime; }
	void setDuration(const string& duration) noexcept { this->duration = duration; }
	vector<Contactor*>& getLinkContactors() noexcept { return this->linkContactors; }
};

