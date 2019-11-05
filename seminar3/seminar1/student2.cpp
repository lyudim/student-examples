#include "student2.h"
#include <iostream>
#include <algorithm>

student2::student2()
{
}

student2::student2(std::string n, int d, int m, int y) :name(n), db(d, m, y)
{
}

student2::student2(std::string n, date d) : name(n), db(d)
{
}

student2::student2(std::string n, int d, int m, int y, std::vector<std::pair<std::string, int>> _marks) : name(n), db(d, m, y), marks(_marks)
{
}

student2::student2(std::string n, date d, std::vector<std::pair<std::string, int>> _marks) : name(n), db(d), marks(_marks)
{
}

std::string student2::get_name() const
{
	return name;
}

void student2::set_name(std::string value)
{
	name = value;
}

date student2::get_date() const
{
	return db;
}

void student2::set_date(date d)
{
	db = d;
}

std::pair<std::string, int> student2::get_mark(int idx) const
{
	return marks[idx];
}

int student2::get_mark(std::string field) const
{
	std::vector<std::string> keys;
	for (auto el : marks) {
		keys.push_back(el.first);
	}

	auto it = find(keys.begin(), keys.end(), field);
	if (it != keys.end()) {
		int i = it - keys.begin();
		return marks[i].second;
	}
	return 0;
}

void student2::set_mark(int idx, int value)
{
}

void student2::set_mark(std::string field, int value)
{
	auto it = find_if(marks.begin(), marks.end(),
		[field](auto p)->bool {return p.first == field; });
	if (it != marks.end()) {
		int i = it - marks.begin();
		marks[i].second = value;
	}
}

void student2::add_mark(std::string field, int value)
{
	marks.push_back(std::pair<std::string, int>(field, value));
}

void student2::remove_mark(int idx)
{
	marks.erase(marks.begin() + idx);
}

void student2::remove_mark(std::string field)
{
	auto it = find_if(marks.begin(), marks.end(),
		[field](auto p)->bool {return p.first == field; });
	if (it != marks.end()) {
		marks.erase(it);

	}
}

int student2::examsTaken() const
{
	return 0;
}

double student2::aveGrade() const
{
	return 0.0;
}

bool student2::operator>(const student2& second) const
{
	return false;
}

bool student2::operator<(const student2& second) const
{
	return false;
}

std::ostream& operator<<(std::ostream& os, const student2& s)
{
	os << s.name << " роден(a) " << s.db << std::endl;
	for (auto it = s.marks.begin(); it != s.marks.end(); it++) {
		os << it->first << "=>" << it->second << "\n";

	}
	return os;
}

