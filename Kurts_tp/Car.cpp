#include "car.h"

car::car(ifstream& fin) // Файловый ввод
{
    for (int i = 0; i < 17; i++)
    {
        getline(fin, info[i]);
    }
}

void car::save(ofstream& fout)// Файловый вывод
{
    for (size_t i = 0; i < 17; i++)
    {
        fout << info[i] << endl;
    }
}

car::car()
{
    cin.clear();
    while (cin.get() != '\n');
    for (size_t i = 0; i < 17; i++)// Ввод со строки
    {
        cout << STATS[i] << ": ";
        getline(cin, info[i]);
    }
}

void car::print()
{
    for (size_t i = 0; i < 17; i++)// Вывод в строку
    {
        cout << STATS[i] << ": " << info[i] << std::endl;
    }
    cout << endl;
}


string car::getModel()
{
    return info[0];
}