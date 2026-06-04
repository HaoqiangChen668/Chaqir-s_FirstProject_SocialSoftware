#pragma once
#include<iostream>
#include <string>
#include <vector>
#include <sstream>

using std::string; using std::vector;

class Common {
public:
	Common() = delete;
	static int inputInt(int min, int max); // 输入整数并校验
	static string inputString(const string& prompt); // 输入提示词读取整行字符串
	static string inputNonEmptyString(const string& prompt); // 输入整行非空字符串
	static vector<string> split(const string& s, char delimiter); // 分割字符串
	static void clearScreen(); // 清屏函数
};