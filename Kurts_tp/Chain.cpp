#include "Chain.h"

Chain::Chain(string filename)
{
    string str;
    int count;

    ifstream fin(filename);

    this->filename = filename;
    next = nullptr;
   
    if (!fin.is_open())
    {
        throw (string)"\x1b[31m������ �������� �����\x1b[0m";
    }
    if (fin.peek() == EOF)
    {
        count = 0;
    }
    else
    {
        getline(fin, str);
        if (str.empty())
            throw (string)"\x1b[31m������ ������ �����\x1b[0m";
        count = stoi(str);
    }
    for (size_t i = 0; i < count; i++)
    {
        car tmp(fin);
        array.push_back(tmp);
    }
    fin.close();
}

Chain* Chain::getNextPtr()
{
    return next;
}

void Chain::set_next(Chain* next_handler)
{
    this->next = next_handler; // ������������ �� ��������� ����������
}

void Chain::print()
{
    if (array.size() == 0)
        throw (string)"\x1b[31m������ ���������� ��� � ����� ���� ������\x1b[0m";
    for (size_t i = 0; i < array.size(); i++)
    {
        array[i].print();
    }
}

void Chain::add()
{
    car tek;
    array.push_back(tek);
    cout << "\x1b[32m���������� ��� ������� ��������\x1b[0m" << endl;
    ofstream out(filename);
    out << array.size() << endl;
    for (size_t i = 0; i < array.size(); i++)
    {
        array[i].save(out);
    }
    out.close();
}

void Chain::del()
{
    int input;
    for (size_t i = 0; i < array.size(); i++)
    {
        cout << "������� " << i << " ��� ��������: " << array[i].getMark() << endl;
    }
    cout << "��� �����: ";
    cin >> input;
    array.erase(array.begin() + input);
    cout << "\x1b[32m������ ���������� ��� ������\x1b[0m" << endl;
    ofstream out(filename);
    out << array.size() << endl;
    for (size_t i = 1; i < array.size(); i++)
    {
        array[i].save(out);
    }
    out.close();
}

void Chain::find_auto(std::string model)
{
    bool found = false;
    string buf;
    for (size_t i = 0; i < array.size(); i++)
    {
        if (model.compare(array[i].getMark()) == 0)
        {
            found = true;
            cout <<"\x1b[32m: ���������� ���������!\x1b[0m � ����� "<< this->filename << endl;
            array[i].print();
        }
    }
    if (!found)
    {
        if (next != nullptr) {
            cout << this->filename << "\x1b[33m: ������ ��� ��������� ������ �� ��������\x1b[0m" << endl;
            next->find_auto(model);
        }
        else
            cout << this->filename << ": \x1b[31m������� ��������. ������� ��������� �� ��� ���������, ���������� ���������.\x1b[0m " << endl;
    }
}