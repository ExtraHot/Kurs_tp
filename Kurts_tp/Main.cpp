#include "handler.h"

int main(int argc, char const* argv[])
{
    setlocale(LC_ALL, "Rus");
    system("chcp 1251");

   

    try 
    {
        handler* salon = new handler("salon");
        salon->set_next(new handler("dealer"));
        salon->getNextPtr()->set_next(new handler("fabrique"));
        handler* ptr = nullptr;
        int input;
        string model;
        while (1)
        {
            system("cls");
            cout << "\t\t||Сервисный центр Hyindai приветсвует вас!||" << endl<< "\t\t\t<Выберете нужное вам действие>"<<endl;
            cout << "1) Поиск нужного автомобиля" << endl
                << "2) Показать модели находящиеся в салоне" << endl
                << "3) Показать модели находящиеся у дилера" << endl
                << "4) Показать модели находящиеся на производстве" << endl
                << "5) Добавление автомобиля" << endl
                << "6) Удаление автомобиля из базы" << endl
                << "0) Выход" << endl
                << "> ";


        }




    }
    catch (string err)
    {
        cout << err << endl;
    }
}