#pragma once
#include "car.h"

using namespace std;

class handler
{
	 handler* next;
     string filename;
	 vector<car> array;
public:
    handler(string filename);
    void find_automobile(string model);
    void print();
    void add();
    void del();

    handler* getNextPtr();
    void set_next(handler* next_handler);

};