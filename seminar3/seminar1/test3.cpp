#include "student2.h"
#include <iostream>
using namespace std;

int main3() {
	system("chcp 1251>nul");
	student2 s("Нина", date(12, 1, 1998),
		vector<pair<string, int>>{ {"Физика", 3}, { "OOП",6 }});
	cout << s << endl;
	s.add_mark("ПИК-1", 5);
	s.add_mark("АВИТО", 6);
	cout << endl << s << endl;
	s.remove_mark(1);
	cout << endl << s << endl;
	s.remove_mark("Физика");
	cout << endl << s << endl;
	s.set_mark("ПИК-1", 6);
	cout << endl << s << endl;
	return 0;
}