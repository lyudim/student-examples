#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "student1.h"
#include "comparator.h";
using namespace std;

class group
{
	vector<student1> list;
	void getStudents() {
		ifstream fin;
		string file;
		cout << "file?";
		cin >> file;

		fin.open(file.c_str());
		if (fin.is_open()) {
			cout << "file is open\n";
			while (!fin.eof())
			{
				string name;
				getline(fin, name);
			//	cout << name << endl;
				string date;
				getline(fin, date);

				int delim1 = date.find(".");
				int delim2 = date.find(".", delim1 + 1);
			//	cout << date << endl;
			//	cout << delim1 << " " << delim2 << endl;

				int day = stoi(date.substr(0, delim1));
			//	cout << "day:" << day << endl;
				int month = stoi(date.substr(delim1 + 1, delim2 - delim1 - 1));
			//	cout << "month:" << month << endl;
				int year = stoi(date.substr(delim2 + 1));
			//	cout << "year=" << year << endl;

				map<string, int> marks;

				string ms;
				getline(fin, ms);
			//	cout << ms << endl;
				int start = 0;
				int current = ms.find(" ");
				while (current != string::npos) {
					string field = ms.substr(start, current - start);
					int mark = stoi(ms.substr(current + 1, 1));
					start = current + 3;
					current = ms.find(" ", start);
				//	cout << field << " " << mark << endl;
					marks.insert(pair<string, int>(field, mark));
				}
				list.push_back(student1(name, day, month, year, marks));
			}
		}
		else {
			cout << "file not found\n";
		}
		fin.close();

	}
public:
	
	group() {
		getStudents();
	}

	friend ostream& operator<<(ostream& os, const group& g) {
		for (auto s : g.list) {
			os << s << endl;
		}
		return os;
	}

	student1& operator[](int i) {
		return list[i];
	}
	const student1& operator[](int i) const {
		return list[i];
	}

	void showByName() {
		vector<student1> list1 = list;
		sort(list1.begin(), list1.end());
		cout << "\nСписък по азбучен ред\n";
		for (auto st : list1) {
			cout << st.get_name() << endl;
		}

	}
	void showByCount() {
		vector<student1> list1 = list;
		sort(list1.begin(), list1.end(), comparator("count"));
		cout << "\nСписък по брой взети изпити\n";
		for (auto st : list1) {
			cout << st.get_name() << "\t" << st.examsTaken()<< endl;
		}
	}
	void showByGrade() {
		vector<student1> list1 = list;
		sort(list1.begin(), list1.end(), comparator("grade"));
		cout << "\nСписък по успех\n";
		for (auto st : list1) {
			cout << st.get_name() << "\t"<<st.aveGrade()<<endl;
		}
	}
};

