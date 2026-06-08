#pragma once
#include <iostream>

#include "OneWeek.h"
#include "contactorList.h"
#include "ReservationForm.h"

class Panel {
private:
	// 基本函数成员
	Week* theWeek;
	ReservationForm* theForm;
	ContactorList* theCList;

	// 文件读取
	void save();
	void load();

	// 初始界面
	void initialInterface();

public:
	Panel();
	~Panel();
	Panel(const Panel& other) = delete;
	Panel& operator=(const Panel& other) = delete;

	// 外部唯一接口
	void open();
};