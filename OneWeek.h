#pragma once
#include <fstream>

#include "day.h"

using std::ofstream;
using std::ifstream;

class Week {

private:
	static const string WEEK_FILE;
	vector<Day> week;
	unordered_map<string, Day*> theDay;

public:
	Week();
	bool saveToFile() const noexcept;
	bool loadFromFile() noexcept;
	vector<vector<Event>> getAll() const noexcept;
	Day* getDay(const string& character) noexcept;
	int getNumOfEventWeek() const noexcept;
};

