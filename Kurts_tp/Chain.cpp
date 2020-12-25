#include "Chain.h"

Chain::Chain(string filename)
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

void Chain::set_next(Chain* next_handler)
{
    this->next = next_handler; // переключение на следующий автомобиль
}

void Chain::print()
{
    if (array.size() == 0)
        throw (string)"Автомобиль не обнаружен";
    for (size_t i = 0; i < array.size(); i++)
    {
        array[i].print();
    }
}

void Chain::add()
{
    car tek;
    array.push_back(tek);
    cout << "Автомобиль был успешно добавлен" << endl;
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
    for (size_t i = 1; i < array.size(); i++)
    {
        cout << "[" << i << "] " << array[i].getModel() << endl;
    }
    cout << "Ваш выбор >";
    cin >> input;
    array.erase(array.begin() + input);
    cout << "Данный автомобиль был удален" << endl;
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
    for (size_t i = 1; i < array.size(); i++)
    {
        if (model.compare(array[i].getModel()) == 0)
        {
            found = true;
            cout << this->filename << ": найден!" << endl;
            array[i].print();
        }
    }
    if (!found)
    {
        if (next != nullptr) {
            cout << this->filename << ": отправляю запрос выше по иерархии" << endl;
            next->find_auto(model);
        }
        else
            cout << this->filename << ": не найден" << endl;
    }
}