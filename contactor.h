#pragma once
#include "common.h"

using std::move;

class Contactor {

private:
	string remark; // 备注
	string birthday; // 生日
	string gender; // 性别
	string signature; // 个性签名
	string phone; // 电话联系方式
	string area; // 地区

public:
	Contactor* next;

	Contactor() {
		this->remark = "用户001";
		this->birthday = "2000-1-1";
		this->gender = "未知";
		this->signature = "这个人很懒，什么都没有留下~";
		this->phone = "空";
		this->area = "未知";
		next = nullptr;
	}

	Contactor(string nickname, string birthday, string gender, string signature, string phone, string area) {
		this->remark = nickname;
		this->birthday = birthday;
		this->gender = gender;
		this->signature = signature;
		this->phone = phone;
		this->area = area;
		next = nullptr;
	}

	Contactor(const Contactor& other) {
		this->remark = other.getRemark();
		this->birthday = other.getBirthday();
		this->gender = other.getGender();
		this->signature = other.getSignature();
		this->phone = other.getPhone();
		this->area = other.getArea();
		next = nullptr;
	}

	// getter部分：获取数据
	string getRemark() const noexcept{ return remark; }
	string getBirthday() const noexcept { return birthday; }
	string getGender() const noexcept { return gender; }
	string getSignature() const noexcept { return signature; }
	string getPhone() const noexcept { return phone; }
	string getArea() const noexcept { return area; }

	// setter部分：设置数据
	void setRemark(const string& remark) noexcept {
		this->remark = remark;
	}
	void setBirthday(const string& birthday) noexcept {
		this->birthday = birthday;
	}
	void setGender(const string& gender) noexcept {
		this->gender = gender;
	}
	void setSignature(const string& signature) noexcept {
		this->signature = signature;
	}
	void setPhone(const string& phone) noexcept {
		this->phone = phone;
	}
	void setArea(const string& area) noexcept {
		this->area = area;
	}

};