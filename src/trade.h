#ifndef TRADE_H
#define TRADE_H

#include <memory>
#include "constants.h"


using namespace std; 

class Student; 

struct Trade { 
    shared_ptr<Student> student1; 
    shared_ptr<Student> student2; 
    ResourceType resource1; 
    ResourceType resource2; 
    string result; 
}; 

#endif


