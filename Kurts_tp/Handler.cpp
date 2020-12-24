#include "handler.h"

handler::handler(string filename)
{
    this->filename = filename;
    next = nullptr;
    string str;
    int count;
    ifstream fin(filename);
    if (!fin.is_open())
    {
        throw (string)"������ �������� �����";
    }
    if (fin.peek() == EOF)
    {
        count = 0;
    }
    else
    {
        getline(fin, str);
        if (str.empty())
            throw (string)"������ ������ �����";
        count = stoi(str);
    }
    for (size_t i = 0; i < count; i++)
    {
        car tmp(fin);
        array.push_back(tmp);
    }
    fin.close();
}

void handler::set_next(handler* next_handler)
{
    this->next = next_handler; // ������������ �� ��������� ����������
}

void handler::print()
{
    if (array.size() == 0)
        throw (string)"� ������ ����� ��� �����������";
    for (size_t i = 0; i < array.size(); i++)
    {
        array[i].print();
    }
}

void handler::add()
{
    car tek;
    array.push_back(tek);
    cout << "����� ���������� ������� ��������" << endl;
    ofstream out(filename);
    out << array.size() << endl;
    for (size_t i = 0; i < array.size(); i++)
    {
        array[i].save(out);
    }
    out.close();
}

void handler::del()
{
    int input;
    for (size_t i = 1; i < array.size(); i++)
    {
        cout << "[" << i << "] " << array[i].getModel() << endl;
    }
    cout << "��� ����� >";
    cin >> input;
    array.erase(array.begin() + input);
    cout << "���������� ������� ������������" << endl;
    ofstream out(filename);
    out << array.size() << endl;
    for (size_t i = 1; i < array.size(); i++)
    {
        array[i].save(out);
    }
    out.close();
}