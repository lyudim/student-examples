#include "student2.h"
#include <iostream>
using namespace std;

int main3() {
	system("chcp 1251>nul");
	student2 s("����", date(12, 1, 1998),
		vector<pair<string, int>>{ {"������", 3}, { "OO�",6 }});
	cout << s << endl;
	s.add_mark("���-1", 5);
	s.add_mark("�����", 6);
	cout << endl << s << endl;
	s.remove_mark(1);
	cout << endl << s << endl;
	s.remove_mark("������");
	cout << endl << s << endl;
	s.set_mark("���-1", 6);
	cout << endl << s << endl;
	return 0;
}