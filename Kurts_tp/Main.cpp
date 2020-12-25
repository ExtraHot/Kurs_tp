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
            cout << "\t\t||��������� ����� Hyindai ����������� ���!||" << endl<< "\t\t\t<�������� ������ ��� ��������>"<<endl;
            cout << "1) ����� ������� ����������" << endl
                << "2) �������� ������ ����������� � ������" << endl
                << "3) �������� ������ ����������� � ������" << endl
                << "4) �������� ������ ����������� �� ������������" << endl
                << "5) ���������� ����������" << endl
                << "6) �������� ���������� �� ����" << endl
                << "0) �����" << endl
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
                cout << "������� �������� ����������: " << endl;
                cin >> model;
                salon->find_auto(model);
                break;
            }

        }




    }
    catch (string err)
    {
        cout << err << endl;
    }
}