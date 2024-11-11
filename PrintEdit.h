#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class PrintEdit {
public:
    PrintEdit();
    PrintEdit(const int& n);
    PrintEdit(const PrintEdit& n);
    virtual ~PrintEdit();

    virtual void print() = 0;
    virtual void edit_inf() = 0;

  

    
};