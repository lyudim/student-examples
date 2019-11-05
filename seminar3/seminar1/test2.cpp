#include "date.h"
#include "student1.h"
#include <iostream>
using namespace std;

int main2() {
	system("chcp 1251>nul");
	student1 s("Павел", date(12, 6, 2000),
		  map<string, int>{ {"Математика",5}, {"Електроника",6}});
	cout << s << endl;
	s.add_mark("ООП", 6);
	s.add_mark("ПЕ", 6);
	s.add_mark("ПЕ", 6);
	s.add_mark("Биология", 5);
	cout << endl << s << endl;
	s.set_mark("Математика", 2);
	s.set_mark("Физика", 6);
	cout << endl << s << endl;

	//нови методи
	cout << "**********************************************\n";
	cout << s << endl;
	cout << "Брой взети изпити:" << s.examsTaken() << endl;
	cout << "Среден успех:" << s.aveGrade() << endl;

	cout << "\nИзпит с пореден номер 1:\n";
	auto exam = s.get_mark(1);
	cout << exam.first << " - " << exam.second << endl;
	
	cout << "\nИзтриваме изпит с пореден номер 1...\n";
	s.remove_mark(1);
	cout << s << endl;

	cout << "\nИзтриваме ООП...\n";
	s.remove_mark("ООП");
	cout << s << endl << endl;

	return 0;
}