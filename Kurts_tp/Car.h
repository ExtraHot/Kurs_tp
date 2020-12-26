#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string STATS[] = { "Модель", "Год","Цвет","Объём двигателя","АКП/МКП","Мощность двигателя","Топливный бак(объём в литрах в литрах)","Расход топлива на 100 км","Габариты","Подогрев руля","abs","eds","Система навигации","Бортовой компьютер","Подогрев сидений","Багажник на крышу","Подушки безопасности" };

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