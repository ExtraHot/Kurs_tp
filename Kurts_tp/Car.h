#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const std::string STATS[] = { "������", "���","����","����� ���������","���/���","�������� ���������","��������� ���(����� � ������ � ������)","������ ������� �� 100 ��","��������","�������� ����","abs","eds","������� ���������","�������� ���������","�������� �������","�������� �� �����","������� ������������" };

class car
{
	string info[17];
public:
	car();
	car(ifstream& fin);
	void print();
	void save(ofstream& fout);
	string getModel();
};