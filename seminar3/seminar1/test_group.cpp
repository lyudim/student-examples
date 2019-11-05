#include "group.h"
#include <iostream>
using namespace std;

int main() {
	system("chcp 1251>nul");
	group g1;
	cout << g1 << endl;
	cout << g1[0] << endl;
	g1.showByName();
	g1.showByCount();
	g1.showByGrade();
}