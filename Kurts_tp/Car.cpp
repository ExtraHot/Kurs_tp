#include "car.h"

car::car()
{
    cin.clear();
    while (cin.get() != '\n');
    for (size_t i = 0; i < 17; i++)
    {
        cout << STATS[i] << ": ";
        getline(cin, info[i]);
    }
}

car::car(ifstream& fin)
{
    for (int i = 0; i < 17; i++)
    {
        getline(fin, info[i]);
    }
}

void car::print()
{
    for (size_t i = 0; i < 17; i++)
    {
        cout << STATS[i] << ": " << info[i] << std::endl;
    }
    cout << endl;
}

void car::save(ofstream& fout)
{
    for (size_t i = 0; i < 17; i++)
    {
        fout << info[i] << endl;
    }
}

string car::getModel()
{
    return info[0];
}