#pragma once
#include "date.h";
#include <vector>
#include <functional>
class student2
{
	std::string name;
	date db; //date born
	std::vector<std::pair<std::string, int>>marks;

public:
	student2();
	student2(std::string n, int d, int m, int y);
	student2(std::string n, date d);
	student2(std::string n, int d, int m, int y,
		std::vector<std::pair<std::string, int>>);
	student2(std::string n, date d, std::vector<std::pair<std::string, int>> _marks);
	std::string get_name() const;
	void set_name(std::string value);

	date get_date() const;
	void set_date(date d);

	std::pair<std::string, int>  get_mark(int idx) const;
	int get_mark(std::string field) const;
	void set_mark(int idx, int value);
	void set_mark(std::string field, int value);

	void add_mark(std::string field, int value);//добавяне в края
	void remove_mark(int idx);
	void remove_mark(std::string field);
	int examsTaken() const;
	double aveGrade() const;
	bool operator>(const student2& second) const;
	bool operator<(const student2& second) const;

	bool operator==(const student2& second) const {
		return name == second.name && db == second.db;
	}

	friend std::ostream& operator<<(std::ostream& os,
		const student2& d);
};


