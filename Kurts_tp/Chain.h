#pragma once
#include "car.h"

using namespace std;

class Chain
{
	 Chain* next;
     string filename;
	 vector<car> array;
public:
    Chain(string filename);

    void find_auto(string model);
    void print();
    void add();
    void del();

    Chain* getNextPtr();
    void set_next(Chain* next_handler);

};