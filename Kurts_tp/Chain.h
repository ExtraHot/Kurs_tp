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
    Chain* getNextPtr(); // Getter
    void set_next(Chain* next_Chain);// Setter
    void find_auto(string mark);
    void print();
    void add();
    void del();

   
};