#include "student.h"
#include <stdexcept>

student::student()
{
	name = "Иван";
	std::cout << "student default ctor\n";
}

student::student(std::string n, int d, int m, int y):
	name(n), db(d,m,y)
{
	//name = n;
//	db = date(d, m, y);
	std::cout << "student 4 parameter ctor\n";
}

student::student(std::string n, int d, int m, int y, std::vector<int> _marks):
	name(n), db(d,m,y), marks(_marks)
{
	std::cout << "student 5 parameter ctor\n";
}
student::student(std::string n, date d, std::vector<int> _marks) :
	name(n), db(d), marks(_marks)
{
	std::cout << "student 3 parameter ctor\n";
}


std::string student::get_name() const
{
	return name;
}

void student::set_name(std::string value)
{
	name = value;
}

date student::get_date() const
{
	return db;
}

void student::set_date(date d)
{
	db = d;
}

//int student::get_mark(int idx) const
//{
//	try {
//		if (idx >= 0 && idx < marks.size()) {
//			return marks[idx];
//		}
//		else {
//			throw "Индексът трябва да е между 0 и " + std::to_string(marks.size() - 1);
//		}
//	}
//	catch (std::string msg) {
//		std::cout << msg << std::endl; exit(-1);
//	}
//
//}

//По-кратък вариант, методът at() изхвърля изключение оut_of_range
int student::get_mark(int idx) const {
	try {
		return marks.at(idx);
	}
	catch (const std::out_of_range e) {
		std::cerr<< "\nИндексът трябва да е между 0 и " + std::to_string(marks.size() - 1)<<std::endl;
		std::cerr << e.what() << std::endl;
		exit(-1);
	}
}



//void student::set_mark(int idx, int value)
//{
//	if (idx >= 0 && idx < marks.size()) {
//		marks[idx] = value;
//	}
//	else {
//		std::cout << "Няма оценка с индекс " << idx << std::endl;
//	}
//}

//алтернативен вариант
void student::set_mark(int idx, int value)
{
	try {
		marks.at(idx)= value;
	 }
	catch ( const std::out_of_range e){
		std::cerr << "\nOценката не е променена, няма оценка с индекс " << idx << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

void student::add_mark(int value)
{
	marks.push_back(value);
}

void student::remove_mark(int idx)
{
	auto it = marks.begin() + idx;
	marks.erase(it);
}

int student::examsTaken() const
{
	int count{ 0 };
	for (auto m : marks) {
		if (m > 2 && m <= 6) count++;
	}
	return count;
}

double student::aveGrade() const
{
	int sum{ 0 };
	for (auto m : marks) if(m!=2) sum += m;
	double aveGrade = static_cast<double>(sum) / examsTaken();
	aveGrade = ceil(aveGrade * 100) / 100;
	return aveGrade;
}

bool student::isBetter(const student& second) const
{
	return aveGrade() > second.aveGrade();
}


bool student::operator<(const student& second) const
{
	return aveGrade() < second.aveGrade();

}

std::ostream& operator<<(std::ostream& os, const student& s)
{
	os << s.name << " роден " << s.db << std::endl;
	os << "Оценки:";
	for (int m : s.marks) {
		os << m << " ";
	}
	return os;
}
