#pragma once
#include <iostream>
#include <string>
#include <map>
#include "date.h"
class student1
{
 std::string name;
  date db; //date born
  std::map<std::string, int>marks;

public:
	student1();
	student1(std::string n, int d, int m, int y);
	student1(std::string n, int d, int m, int y,
		std::map<std::string, int>_marks);
	student1(std::string n, date d,
		std::map<std::string, int>_marks);
	std::string get_name() const;
	void set_name(std::string value);

	date get_date() const;
	void set_date(date d);

	std::pair<std::string, int> get_mark(int idx) const;
	int get_mark(std::string field);

	void set_mark(std::string field, int value);

	void add_mark(std::string field, int value);//dobavyane v kraya
	void remove_mark(int idx);
	void remove_mark(std::string field);

	int examsTaken() const;
	double aveGrade() const;

	bool operator < (const student1& second) const;
	bool operator>(const student1& second) const;

	friend std::ostream& operator<<(std::ostream& os,
		const student1& d);
};

