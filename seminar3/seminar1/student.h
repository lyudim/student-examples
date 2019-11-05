#pragma once
#include "date.h";
#include <vector>

class student
{
	std::string name;
	date db; //date born
	std::vector<int>marks;

public:
	student();
	student(std::string n, int d, int m, int y);
	student(std::string n, int d, int m, int y,
		std::vector<int>_marks);
	student(std::string n, date d,
		std::vector<int>_marks);
	std::string get_name() const;
	void set_name(std::string value);

	date get_date() const;
	void set_date(date d);

	int get_mark(int idx) const;
	void set_mark(int idx, int value);

	void add_mark(int value);//добавяне в края
	void remove_mark(int idx);

	int examsTaken() const;
	double aveGrade() const;

	bool isBetter(const student& second) const;
	bool operator<(const student& second) const;
	
	friend std::ostream& operator<<(std::ostream& os,
		const student& d);
};

