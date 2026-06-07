#include "event.h"

int Event::cntOfId = 0;

Event::~Event() {
	for (auto& p : linkContactors) {
		delete p;
	}
}