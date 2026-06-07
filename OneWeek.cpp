#include "OneWeek.h"

const string Week::WEEK_FILE = "week.txt";

Week::Week() {
	for (int i = 0; i < 7; ++i) {
		Day oneDay;
		week.emplace_back(oneDay);
	}
	theDay = {
		{"一", &week.at(0)},
		{"二", &week.at(1)},
		{"三", &week.at(2)},
		{"四", &week.at(3)},
		{"五", &week.at(4)},
		{"六", &week.at(5)},
		{"七", &week.at(6)}
	};
}

bool Week::saveToFile() const noexcept {
	ofstream fout(WEEK_FILE);
	if (!fout.is_open()) return false;

	vector<vector<Event>> allEvent = getAll();
	for (int i = 0; i < allEvent.size(); ++i) {
		fout << allEvent.at(i).size() << '\n';
		vector<Event>& dayEvent = allEvent.at(i);
		for (Event& event : dayEvent) {
			fout << event.getTheme() << '|';
			fout << event.getDescription() << '|';
			fout << event.getRemark() << '|';
			fout << event.getStartTime() << '|';
			fout << event.getDuration() << '|' << '\n';
			vector<Contactor*>& lc = event.getLinkContactors();
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
	}

	fout.close();
	return true;
}

bool Week::loadFromFile() noexcept {
	ifstream fin(WEEK_FILE);
	if (!fin.is_open()) return false;

	for (auto& day : week) day.clear();

	for (int i = 0; i < week.size(); ++i) {
		Day& day = week.at(i);
		int dayNumOfEvent;
		fin >> dayNumOfEvent; fin.ignore();
		for (int j = 0; j < dayNumOfEvent; ++j) {
			string s;
			getline(fin, s);
			vector<string> info = Common::split(s, '|');
			vector<Contactor*> lc;
			int numOfContactor;
			fin >> numOfContactor; fin.ignore();
			for (int k = 0; k < numOfContactor; ++k) {
				string ss;
				getline(fin, ss);
				vector<string> info_c = Common::split(ss, '|');
				Contactor* newContactor = new Contactor(info_c.at(0), info_c.at(1), info_c.at(2), info_c.at(3), info_c.at(4), info_c.at(5));
				lc.emplace_back(newContactor);
			}
			EventNode* event = new EventNode(info.at(0), info.at(1), info.at(2), info.at(3), info.at(4), lc);
			day.addEvent(event);
		}
	}

	fin.close();
	return true;
}

vector<vector<Event>> Week::getAll() const noexcept{
	vector<vector<Event>> ans;
	for (auto& day : week) {
		ans.emplace_back(day.getAllEvent());
	}
	return ans;
}

Day* Week::getDay(const string& character) noexcept {
	if (theDay.count(character) == 0) {
		return nullptr;
	}
	return theDay[character];
}

int Week::getNumOfEventWeek() const noexcept {
	int ans = 0;
	for (const auto& day : week) {
		ans += day.getNumOfEvent();
	}
	return ans;
}