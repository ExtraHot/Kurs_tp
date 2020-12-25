#pragma once
#include "car.h"

using namespace std;

class Chain
{
	 Chain* next;
	 vector<car> array;
     string filename;
public:
    Chain(string filename);
    Chain* getNextPtr();
    void set_next(Chain* next_handler);
    void find_auto(string model);
    void print();
    void add();
    void del();

   
};