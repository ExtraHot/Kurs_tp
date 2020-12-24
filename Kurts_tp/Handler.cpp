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