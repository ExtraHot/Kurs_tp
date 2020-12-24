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
        throw (string)"Ошибка открытия файлы";
    }
    if (fin.peek() == EOF)
    {
        count = 0;
    }
    else
    {
        getline(fin, str);
        if (str.empty())
            throw (string)"Ошибка чтения файла";
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
    this->next = next_handler; // переключение на следующий автомобиль
}

void handler::print()
{
    if (array.size() == 0)
        throw (string)"В данном месте нет автомобилей";
    for (size_t i = 0; i < array.size(); i++)
    {
        array[i].print();
    }
}

void handler::add()
{
    car tek;
    array.push_back(tek);
    cout << "Новый автомобиль успешно добавлен" << endl;
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
    cout << "Ваш выбор >";
    cin >> input;
    array.erase(array.begin() + input);
    cout << "Автомобиль успешно утилизирован" << endl;
    ofstream out(filename);
    out << array.size() << endl;
    for (size_t i = 1; i < array.size(); i++)
    {
        array[i].save(out);
    }
    out.close();
}