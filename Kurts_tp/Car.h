#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string STATS[] = { "������", "���","����","����� ���������","���/���","�������� ���������","��������� ���(����� � ������ � ������)","������ ������� �� 100 ��","��������","�������� ����","abs","eds","������� ���������","�������� ���������","�������� �������","�������� �� �����","������� ������������" };

class car
{
	string info[17];
public:
	car();
	car(ifstream& fin);

	void print();
	void save(ofstream& fout);

	string getMark();// Getter
};