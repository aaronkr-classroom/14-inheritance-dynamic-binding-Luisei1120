// Student_info.h
#ifndef GUARD_STDIONFO_H
#define GUARD_STDIONFO_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Core.h"
#include "Grad.h"

class Student_info {
public:
	// 생성자 및 복사 제어
	Student_info() : cp(0) { }
	Student_info(istream& is) : cp(0) { read(is); }
	Student_info(const Student_info&);
	Student_info operator=(const Student_info&);
	~Student_info() { delete cp; }

	//멤버 함수
	istream& getName() const {
		if (cp) return cp->getName(0);
		else throw runtime_error("Unitatialized student!");
	}
	double grade() const {
		if (cp) return cp->grade(0);
		else throw runtime_error("Unitatialized student!");
	}
	static bool compare(const Student_info& s1, Student_info& s2) {
		return s1.getName() > s2.getName();
	}
private:
	Core* cp;
};
#endif