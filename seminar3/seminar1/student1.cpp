#include "student1.h"
#include <functional>

student1::student1()
{
}

student1::student1(std::string n, int d, int m, int y) :name(n), db(d, m, y)
{
}

student1::student1(std::string n, int d, int m, int y, std::map<std::string, int> _marks): name(n), db(d, m, y), marks(_marks)
{
}

student1::student1(std::string n, date d, std::map<std::string, int> _marks):name(n), db(d), marks(_marks)
{
}

std::string student1::get_name() const
{
	return name;
}

void student1::set_name(std::string value)
{
	name = value;
}

date student1::get_date() const
{
	return db;
}

void student1::set_date(date d)
{
  db=d;
}

std::pair<std::string, int> student1::get_mark(int idx) const
{
	auto it = marks.begin();
	for (int i{ 0 }; i < idx; i++) it++;
	if (it != marks.end()) {
		return std::make_pair(it->first, it->second);
	}
	else {
		std::cout << "Няма оценка с номер " << idx << "\n";
		return std::pair<std::string, int>("", 0);
	}
	
}

int student1::get_mark(std::string field)
{
	auto it = marks.find(field);
	if (it != marks.end()) {
		return it->second;
	}
	else {
		std::cout << "Няма оценка по " << field << "\n";
	}
	return 0;
}

void student1::set_mark(std::string field, int value)
{
	auto it = marks.find(field);
	if (it != marks.end()) {
		it->second = value; //marks[field]=value
	}
	else {
		std::cout << "Изпитът " <<field<<" не е в списъка\n";
	}
	
}

void student1::add_mark(std::string field, int value)
{
	// insert vrysta pair, second- success of insertion
	auto p = marks.insert(std::pair<std::string, int>(field, value));
	if (p.second == false) {
		std::cout << "Изпитът " << field << " вече е в списъка\n";
	}
}

void student1::remove_mark(int idx)
{
	auto it = marks.begin();
	for (int i{ 1 }; i < marks.size(); i++) it++;
	if (it != marks.end() ){
		marks.erase(it);
	}
	else {
		std::cout << "Няма оценка с номер " << idx << std::endl;
	}
}

void student1::remove_mark(std::string field)
{
	auto it = marks.find(field);
	if (it != marks.end() ) {
		marks.erase(it);
	}
	else {
		std::cout<<"Няма оценка по "<<field<<std::endl;
	}
}

int student1::examsTaken() const
{
	int count = 0;
	for (auto it = marks.begin(); it != marks.end(); it++) {
		if (it->second > 2) count++;
	}
	return count;
}

double student1::aveGrade() const
{
	int total = 0;
	for (auto it = marks.begin(); it != marks.end(); it++) {
		if(it->second>2 )total += it->second;
	}
	double aveGrade = static_cast<double>(total) / examsTaken();
	aveGrade = ceil(aveGrade * 100) / 100;
	return aveGrade;
}

bool student1::operator>(const student1& second) const
{
	//return aveGrade()>second.aveGrade();
	return  name > second.name;
}

bool student1::operator<(const student1& second) const
{
	return !(*this > second);
}



std::ostream& operator<<(std::ostream& os, const student1& s)
{
	os << s.name << " дата на раждане " << s.db<<"\n";
	for (auto it = s.marks.begin(); it != s.marks.end(); it++) {
		os << it->first << " --> " << it->second << "\n";
	}
	return os;
}
