#pragma once
#include "PrintEdit.h"
#include "Poet.h"
#include "Novelist.h"
#include "Scifi.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Element {
    Element* next;
    PrintEdit* data;
};

class Keeper {
private:
    Element* head;
    Element* tail;
    int count;

public:
    Keeper();
    Keeper(Element* h, Element* t, int c);
    Keeper(const Keeper& other);
    ~Keeper();

    Element* get_head();
    Element* get_tail();
    int get_count();

    void delete_all();
    Keeper& delete_element(int n);
    Keeper& edit_element(int n);

    void add_to_head(PrintEdit* item);
    void add_to_tail(PrintEdit* item);

    Keeper& operator++(); // Adds an element at the beginning
    friend Keeper& operator++(Keeper& K, int); // Adds an element at the end

    Keeper& operator--(int); // Deletes the last element
    friend Keeper& operator--(Keeper& K); // Deletes the first element

    void print_keeper();
    void print_element(int n);

    void load_from_file(const string& filename);
    void save_to_file(const string& filename);
};
