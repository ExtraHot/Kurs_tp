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
            cout << "\t\t\t\t\t\x1b[31m||��������� ����� Hyindai ����������� ���!||" << endl << "\t\t\t\t\t\t<�������� ������ ��� ��������>\x1b[0m" << endl;
            cout << "\x1b[33m1) |����� ������� ����������|" << endl
                << "2) |�������� ������ ����������|" << endl
                << "3) |���������� ����������|" << endl
                << "4) |�������� ���������� �� ����|" << endl
                << "0) |�����|" << endl
                << "��� �����: \x1b[0m";

            while (!(cin >> input) || (cin.peek() != '\n'))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "\x1b[31m������ ����� �����!\x1b[0m\n> ";
            }
            switch (input)
            {
            case 1:
                cout << "������� �������� ����������: " << endl;
                cin >> mark;
                Market->find_auto(mark);
                break;
            case 2:

                system("cls");
                cout << "��� �� ������ ���������� ����������? " << endl
                    << "1 -> � ������" << endl
                    << "2 -> � ������ ������" << endl
                    << "3 -> � ���������������� ����" << endl
                    << "��� ����� : " << endl;

                while (!(cin >> input) || (cin.peek() != '\n') || input > 3)
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "\x1b[31m������ ����� �����!\x1b[0m\n> ";
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
                cout << "���� ����� �������� ����?" << endl
                    << "1 -> � �����" << endl
                    << "2 -> � ����� ������" << endl
                    << "3 -> � ���������������� ���" << endl
                    << "��� ����� : ";

                while (!(cin >> input) || (cin.peek() != '\n' || input > 3))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "\x1b[31m������ ����� �����!\x1b[0m\n> ";
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
                cout << "������ �� ������ ������ ����������?" << endl
                    << "1) � ������" << endl
                    << "2) � ������ ������" << endl
                    << "3) � ���������������� ����" << endl
                    << "��� ����� : ";
                while (!(cin >> input) || (cin.peek() != '\n' || input > 3))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "\x1b[31m������ ����� �����!\x1b[0m\n> ";
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