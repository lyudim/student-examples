#include "date.h"
#include "student.h"
#include <iostream>
using namespace std;

int main1() {
	system("chcp 1251>nul");
	//date d1;
	//cout << d1 << endl;
	///*cout << "въведете дата д м г ";
	//cin >> d1;*/
	///*cout << "d1\n";
	//cout << d1 << endl;*/
	//date d2(25, 7, 2007);
	//cout << d2 << endl;

	//cout << "student class\n";
	//student s1;
	//cout << "s2\n";
	//student s2("Павел", 12, 6, 1998);

	//cout << "s3\n";
	//student s3("Димитър", 5, 11, 2000,
	//	vector<int>{5, 6, 6, 6});
	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s3 << endl;
	//s3.remove_mark(1);
	//cout << s3 << endl;

	cout << "Семинар 2\n";
	student s1("Петко", date(12, 3, 1998), vector<int>{4, 6, 6});
	cout << s1 << endl;
	s1.add_mark(5);
	s1.add_mark(2);
	cout << endl << s1 << endl;
	cout << "Брои взети изпити:" << s1.examsTaken()
		<< " ср.успех:" << s1.aveGrade() << endl;
	s1.set_mark(4, 6);
	s1.remove_mark(0);
	cout << endl << s1 << endl;
	cout << "Брои взети изпити:" << s1.examsTaken()
		<< " ср,успех:" << s1.aveGrade() << endl;

	s1.set_mark(10, 6);
	cout << s1.get_mark(10) << endl;
	cout << "bye\n";

	return 0;
}