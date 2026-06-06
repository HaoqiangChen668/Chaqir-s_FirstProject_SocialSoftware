#include "user.h"

const string Userinfo::USER_FILE = "user_info.txt";

bool Userinfo::saveToFile() noexcept {
	ofstream fout(USER_FILE);
	if (!fout.is_open()) return false;
	fout << nickname << '|';
	fout << birthday << '|';
	fout << gender << '|';
	fout << signature << '|';
	fout << phone << '|';
	fout << area << '|' << endl;
	fout.close();
	return true;
}

bool Userinfo::loadFromFile() noexcept {
	ifstream fin(USER_FILE);
	if (!fin.is_open()) return false;
	string information;
	getline(fin, information);
	vector<string> info = Common::split(information, '|');
	nickname = info.at(0);
	birthday = info.at(1);
	gender = info.at(2);
	signature = info.at(3);
	phone = info.at(4);
	area = info.at(5);
	fin.close();
	return true;
}