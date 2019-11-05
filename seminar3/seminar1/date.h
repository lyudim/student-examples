#pragma once
#include <string>
#include <iostream>
class date
{
private:
	int day;
	int month;
	int year;
	//������� ����-�������
	void setDate(int d, int m, int y);
	bool isLeap(int y) const;
	//������� ������
	static const int m_days[13]; //���� ��� � ��������
	static const std::string m_names[13];
public:
	date();
	date(int _d, int _m, int _y);
	int get_day() const;
	int get_month() const;
	int get_year() const;

	//���� - �������� �� ���������
	bool operator<(const date& second)const;
	bool operator>(const date& second)const;

	bool operator==(const date& second)const;
	bool operator!=(const date& second)const;

	friend std::ostream& operator<<(std::ostream& os,
		const date& d);
	friend std::istream& operator>>(std::istream&,
		date& d);
};

