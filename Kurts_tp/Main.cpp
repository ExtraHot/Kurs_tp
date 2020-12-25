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



        }




    }
    catch (string err)
    {
        cout << err << endl;
    }
}