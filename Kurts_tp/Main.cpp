#include "Chain.h"

int main(int argc, char const* argv[])
{
    setlocale(LC_ALL, "Rus");
    system("chcp 1251");

   

    try 
    {
        Chain* salon = new Chain("salon");
        salon->set_next(new Chain("dealer"));
        salon->getNextPtr()->set_next(new Chain("fabrique"));
        Chain* ptr = nullptr;
        int input;
        string model;
        while (1)
        {
            system("cls");
            cout << "\t\t||��������� ����� Hyindai ����������� ���!||" << endl<< "\t\t\t<�������� ������ ��� ��������>"<<endl;
            cout << "1) ����� ������� ����������" << endl
                << "2) �������� ������ ����������" << endl
                << "3) ���������� ����������" << endl
                << "4) �������� ���������� �� ����" << endl
                << "5) �����" << endl
                << "> ";

            while (!(cin >> input) || (cin.peek() != '\n'))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "������ ����� �����!\n> ";
            }
            switch (input)
            {
            case 1:
                cout << "������� �������� ����������(english): " << endl;
                cin >> model;
                salon->find_auto(model);
                break;
            case 2:

                system("cls");
                cout << "��� �� ������ ���������� ����������? " << endl
                    << "1 -> � ������" << endl
                    << "2 -> � ������ ������" << endl
                    << "3 -> � ���������������� ����" << endl
                    << "��� ����� : ";

                while (!(cin >> input) || (cin.peek() != '\n'))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "������ ����� �����!\n> ";
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
                cout << "���� ����� �������� ����?" << endl
                    << "1 -> � �����" << endl
                    << "2 -> � ����� ������" << endl
                    << "3 -> � ���������������� ���" << endl
                    << "��� ����� : ";

                while (!(cin >> input) || (cin.peek() != '\n'))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "������ ����� �����!\n> ";
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
      
                
            }

        }




    }
    catch (string err)
    {
        cout << err << endl;
    }
}