#include "Chain.h"

int main(int argc, char const* argv[])
{
    setlocale(LC_ALL, "Rus");
    system("chcp 1251");

   

    try 
    {
        string mark;
        Chain* salon = new Chain("salon");
        salon->set_next(new Chain("dealer"));
        salon->getNextPtr()->set_next(new Chain("fabrique"));
        Chain* ptr = nullptr;
        int input;
      
        while (1)
        {
            system("cls");
            cout << "\t\t\t\t\t||Сервисный центр Hyindai приветсвует вас!||" << endl<< "\t\t\t\t\t\t<Выберете нужное вам действие>"<<endl;
            cout << "1) Поиск нужного автомобиля" << endl
                << "2) Показать модели автомобиля" << endl
                << "3) Добавление автомобиля" << endl
                << "4) Удаление автомобиля из базы" << endl
                << "5) Выход" << endl
                << "> ";

            while (!(cin >> input) || (cin.peek() != '\n'))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Ошибка ввода числа!\n> ";
            }
            switch (input)
            {
            case 1:
                cout << "Введите название автомабиля(english): " << endl;
                cin >> mark;
                salon->find_auto(mark);
                break;
            case 2:

                system("cls");
                cout << "Где вы хотите посмотреть автомобили? " << endl
                    << "1 -> В салоне" << endl
                    << "2 -> В центре дилера" << endl
                    << "3 -> В производственном цеху" << endl
                    << "Ваш выбор : ";

                while (!(cin >> input) || (cin.peek() != '\n'))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Ошибка ввода числа!\n> ";
                }
                switch (input)
                {
                case 1:
                    salon->print();
                    break;
                case 2:
                    salon->getNextPtr()->print();
                    break;
                case 3:
                    salon->getNextPtr()->getNextPtr()->print();
                    break;
                default:
                    break;
                }

                
            case 3:

                system("cls");
                cout << "Куда нужно добавить Авто?" << endl
                    << "1 -> В салон" << endl
                    << "2 -> В центр дилера" << endl
                    << "3 -> В производственный цех" << endl
                    << "Ваш выбор : ";

                while (!(cin >> input) || (cin.peek() != '\n'))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Ошибка ввода числа!\n> ";
                }
                switch (input)
                {
                case 1:
                    ptr = salon;
                    break;
                case 2:
                    ptr = salon->getNextPtr();
                    break;
                case 3:
                    ptr = salon->getNextPtr()->getNextPtr();
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
                while (!(cin >> input) || (cin.peek() != '\n'))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Ошибка ввода числа!\n> ";
                }
                switch (input)
                {
                case 1:
                    ptr = salon;
                    break;
                case 2:
                    ptr = salon->getNextPtr();
                    break;
                case 3:
                    ptr = salon->getNextPtr()->getNextPtr();
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

     }

    catch (string err)
    {
        cout << err << endl;
    }
}