#include "date.h"
#include "student1.h"
#include <iostream>
using namespace std;

int main2() {
	system("chcp 1251>nul");
	student1 s("�����", date(12, 6, 2000),
		  map<string, int>{ {"����������",5}, {"�����������",6}});
	cout << s << endl;
	s.add_mark("���", 6);
	s.add_mark("��", 6);
	s.add_mark("��", 6);
	s.add_mark("��������", 5);
	cout << endl << s << endl;
	s.set_mark("����������", 2);
	s.set_mark("������", 6);
	cout << endl << s << endl;

	//���� ������
	cout << "**********************************************\n";
	cout << s << endl;
	cout << "���� ����� ������:" << s.examsTaken() << endl;
	cout << "������ �����:" << s.aveGrade() << endl;

	cout << "\n����� � ������� ����� 1:\n";
	auto exam = s.get_mark(1);
	cout << exam.first << " - " << exam.second << endl;
	
	cout << "\n��������� ����� � ������� ����� 1...\n";
	s.remove_mark(1);
	cout << s << endl;

	cout << "\n��������� ���...\n";
	s.remove_mark("���");
	cout << s << endl << endl;

	return 0;
}