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
        throw (string)"\x1b[31mОшибка открытия файлы\x1b[0m";
    }
    if (fin.peek() == EOF)
    {
        count = 0;
    }
    else
    {
        getline(fin, str);
        if (str.empty())
            throw (string)"\x1b[31mОшибка чтения файла\x1b[0m";
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
    this->next = next_handler; // переключение на следующий автомобиль
}

void Chain::print()
{
    if (array.size() == 0)
        throw (string)"\x1b[31mТакого автомобиля нет в нашей базе данных\x1b[0m";
    for (size_t i = 0; i < array.size(); i++)
    {
        array[i].print();
    }
}

void Chain::add()
{
    car tek;
    array.push_back(tek);
    cout << "\x1b[32mАвтомобиль был успешно добавлен\x1b[0m" << endl;
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
        cout << "Введите " << i << " для удаления: " << array[i].getMark() << endl;
    }
    cout << "Ваш выбор: ";
    cin >> input;
    array.erase(array.begin() + input);
    cout << "\x1b[32mДанный автомобиль был удален\x1b[0m" << endl;
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
            cout <<"\x1b[32m: Автомобиль обнаружен!\x1b[0m в месте "<< this->filename << endl;
            array[i].print();
        }
    }
    if (!found)
    {
        if (next != nullptr) {
            cout << this->filename << "\x1b[33m: Запрос был отправлен дальше по иерархии\x1b[0m" << endl;
            next->find_auto(model);
        }
        else
            cout << this->filename << ": \x1b[31mЗапросы выплнены. Искомый результат не был обнаружен, автомобиль отсутвует.\x1b[0m " << endl;
    }
}