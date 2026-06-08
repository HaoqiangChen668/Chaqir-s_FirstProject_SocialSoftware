#include "Panel.h"

void Panel::save() {
	this->theWeek->saveToFile();
	this->theCList->saveToFile();
	this->theForm->saveToFile();
}

void Panel::load() {
	this->theWeek->loadFromFile();
	this->theCList->loadFromFile();
	this->theForm->loadFromFile();
}

Panel::Panel() {
	this->theWeek = new Week();
	this->theCList = new ContactorList();
	this->theForm = new ReservationForm();
	load();
}

Panel::~Panel() {
	save();
	delete this->theWeek;
	delete this->theCList;
	delete this->theForm;
}

void Panel::open() {
	return;
}