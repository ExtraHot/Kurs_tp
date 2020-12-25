#include "Chain.h"
#include "windows.h"

int main(int argc, char const* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    system("chcp 1251");
 
   

    try 
    {
        string mark;
        Chain* Market = new Chain("salon");
        Market->set_next(new Chain("dealer"));
        Market->getNextPtr()->set_next(new Chain("fabrique"));
        Chain* ptr = nullptr;
        int input;
      
        while (1)
        {
            try
            {
            system("cls");
            cout << "\t\t\t\t\t\x1b[31m||Сервисный центр Hyindai приветсвует вас!||" << endl << "\t\t\t\t\t\t<Выберете нужное вам действие>\x1b[0m" << endl;
            cout << "\x1b[33m1) |Поиск нужного автомобиля|" << endl
                << "2) |Показать модели автомобиля|" << endl
                << "3) |Добавление автомобиля|" << endl
                << "4) |Удаление автомобиля из базы|" << endl
                << "0) |Выход|" << endl
                << "Ваш выбор: \x1b[0m";

            while (!(cin >> input) || (cin.peek() != '\n'))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "\x1b[31mОшибка ввода числа!\x1b[0m\n> ";
            }
            switch (input)
            {
            case 1:
                cout << "Введите название автомабиля: " << endl;
                cin >> mark;
                Market->find_auto(mark);
                break;
            case 2:

                system("cls");
                cout << "Где вы хотите посмотреть автомобили? " << endl
                    << "1 -> В салоне" << endl
                    << "2 -> В центре дилера" << endl
                    << "3 -> В производственном цеху" << endl
                    << "Ваш выбор : " << endl;

                while (!(cin >> input) || (cin.peek() != '\n') || input > 3)
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "\x1b[31mОшибка ввода числа!\x1b[0m\n> ";
                }
                switch (input)
                {
                case 1:
                    Market->print();
                    break;
                case 2:
                    Market->getNextPtr()->print();
                    break;
                case 3:
                    Market->getNextPtr()->getNextPtr()->print();
                    break;
                default:
                    break;
                }
                break;


            case 3:

                system("cls");
                cout << "Куда нужно добавить Авто?" << endl
                    << "1 -> В салон" << endl
                    << "2 -> В центр дилера" << endl
                    << "3 -> В производственный цех" << endl
                    << "Ваш выбор : ";

                while (!(cin >> input) || (cin.peek() != '\n' || input > 3))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "\x1b[31mОшибка ввода числа!\x1b[0m\n> ";
                }
                switch (input)
                {
                case 1:
                    ptr = Market;
                    break;
                case 2:
                    ptr = Market->getNextPtr();
                    break;
                case 3:
                    ptr = Market->getNextPtr()->getNextPtr();
                    break;
                default:
                    break;
                }
                ptr->add();
                break;

            case 4:
                system("cls");
                cout << "Откуда вы хотите убрать автомобиль?" << endl
                    << "1) В салоне" << endl
                    << "2) В центре дилера" << endl
                    << "3) В производственном цехе" << endl
                    << "Ваш выбор : ";
                while (!(cin >> input) || (cin.peek() != '\n' || input > 3))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "\x1b[31mОшибка ввода числа!\x1b[0m\n> ";
                }
                switch (input)
                {
                case 1:
                    ptr = Market;
                    break;
                case 2:
                    ptr = Market->getNextPtr();
                    break;
                case 3:
                    ptr = Market->getNextPtr()->getNextPtr();
                    break;
                default:
                    break;
                }
                ptr->del();
                break;
            case 0:
                return 0;
            default:
                break;
            }
            system("pause");
        }
            catch (string err)
            {
                cout << err << endl;
                system("pause");
            }
            }

     }

    catch (string err)
    {
        cout << err << endl;
    }
}