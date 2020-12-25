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
        Chain* Market = new Chain("Салон");
        Market->set_next(new Chain("Дилер"));
        Market->getNextPtr()->set_next(new Chain("Производство"));
        Chain* ptr = nullptr;
        int input;
      
        while (1)
        {
            try
            {
            system("cls");
            cout << "\t\t\t\t\t\x1b[31m||Сервисный центр Hyundai приветсвует вас!||" << endl << "\t\t\t\t\t       <Выберете нужное вам действие>\x1b[0m" << endl;
            cout << "\x1b[33m1) |Поиск нужного автомобиля|" << endl
                << "2) |Показать модели автомобилeй|" << endl
                << "3) |Добавление автомобиля|" << endl
                << "4) |Удаление автомобиля из базы|" << endl
                << "0) |Выход|" << endl
                << "Ваш выбор: \x1b[0m";

            while (!(cin >> input) || (cin.peek() != '\n'|| input > 4))
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
                cout << "\x1b[32mГде вы хотите посмотреть автомобили?\x1b[0m " << endl
                    << "1 -> В салоне" << endl
                    << "2 -> В центре дилера" << endl
                    << "3 -> В производственном цеху" << endl
                    << "Ваш выбор : " << endl;

                while (!(cin >> input) || (cin.peek() != '\n') || input > 3)
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "\x1b[33mОшибка ввода числа!\x1b[0m\n> ";
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
                cout << "\x1b[32mКуда нужно добавить Авто?\x1b[0m" << endl
                    << "Что-бы добавить в салон нажмите-> 1" << endl
                    << "Что-бы добавить в центр дилера нажмите-> 2" << endl
                    << "Что-бы добавить в цех производства нажмите-> 3" << endl
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
                cout << "\x1b[31mОткуда вы хотите убрать автомобиль?\x1b[0m" << endl
                    << "Что-бы удалить из салона нажмите-> 1" << endl
                    << "Что-бы удалить из центра дилера нажмите-> 2" << endl
                    << "Что-бы удалить из цеха производства нажмите-> 3" << endl
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