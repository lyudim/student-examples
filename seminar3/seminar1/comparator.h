#pragma once
#include<string>
#include "student1.h"
class comparator
{
	std::string prop;
public:
	comparator(std::string p) :prop(p) {}
	bool operator () (const student1& s1, const student1& s2) {
		if (prop == "count") {
			return s1.examsTaken() < s2.examsTaken();
		}
		if (prop == "grade") {
			return s1.aveGrade() < s2.aveGrade();
		}
		return s1 < s2;
	}
	
};

