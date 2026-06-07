#include "common.h"

using std::cin; using std::cout;
using std::getline;
using std::stringstream;

// cin.ignore(1024, '\n'); 清空到换行符'\n'，包括'\n';

// 输入整数并校验
int Common::inputInt(int min, int max) {
	int num;
	while (true) {
		cin >> num;
		if (cin.fail() || num < min || num > max) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入无效 请重新输入：";
		}
		else {
			cin.ignore(1024, '\n');
			return num;
		}
	}
}

// 输入提示词读取整行字符串
string Common::inputString(const string& prompt) {
	cout << prompt;
	string input;
	getline(cin, input);
	return input;
}

// 输入整行非空字符串
string Common::inputNonEmptyString(const string& prompt) {
	string s;
	while (s.empty()) {
		s = inputString(prompt);
		if (s.empty()) {
			cout << "输入不能为空喔 重新输入！\n";
		}
	}
	return s;
}

// 分割字符串
vector<string> Common::split(const string& s, char delimiter) {
	vector<string> parts;
	stringstream ss(s);
	string part;
	while (getline(ss, part, delimiter)) {
		parts.emplace_back(part);
	}
	return parts;
}

// 清屏函数
void Common::clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}