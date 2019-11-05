#include "date.h"


const int date::m_days[13]{ 0, 31,28,31,
   30, 31,30, 31,31,30,31,30,31
};


//брои дни в месеците
const std::string date::m_names[13]{
	"", "януари","февруари","март",
	"април", "май","юни","юли",
	"август","септември", "октомври",
	"ноември", "декември"
};

void date::setDate(int d, int m, int y)
{
	year = (y >= 1970 && y <= 2003) ? y : 2000;
	month = (m >= 1 && m <= 12) ? m : 1;
	if (month == 2 && isLeap(year)) {
		day = (d >= 1 && d <= 29) ? d : 1;
	}
	else {
		day = (d >= 1 && d <= date::m_days[month]) ? d : 1;
	}

}

bool date::isLeap(int y) const
{
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
		return true;
	return false;
}

date::date()
{
//	std::cout << "date default ctor\n";
	setDate(1, 1, 2000);
}

date::date(int _d, int _m, int _y)
{ 
//	std::cout << "date parameter ctor\n";
	setDate(_d, _m, _y);
}

int date::get_day() const
{
	return day;
}

int date::get_month() const
{
	return month;
}

int date::get_year() const
{
	return year;
}

//операции за сравнение - реализация
bool date::operator<(const date& second) const {
	if (year > second.year) {
		return true;
	}
	else if (year < second.year) {
		return false;
	}
	else {
		if (month > second.month) {
			return true;
		}
		else if (month < second.month) {
			return false;
		}
		else {
			if (day > second.day) {
				return true;
			}
			else if (day < second.day) {
				return false;
			}

		}

	}
}

bool date::operator>(const date& second) const{
	return !(*this < second);
}

bool date::operator==(const date& second) const {
	return year == second.year && month == second.month && day == second.day;
}
bool date::operator!=(const date& second) const{
	return !(*this == second);
}


std::ostream& operator<<(std::ostream& os, const date& d)
{
	os << d.day << " " 
	  << date::m_names[d.month] << " " << d.year << " г.";
	return os;

}

std::istream& operator>>(std::istream& is, date& d)
{
	is >> d.day >> d.month >> d.year;
	return is;
}
