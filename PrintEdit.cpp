#include "PrintEdit.h"
PrintEdit::PrintEdit() { cout << "Вызван конструктор класса Figur\n"; };
PrintEdit::PrintEdit(const int& n) { cout << "Вызван конструктор c параметрами класса Figur\n"; }
PrintEdit::PrintEdit(const PrintEdit& n) { cout << "Вызван конструктор копирования класса Figur\n"; };
PrintEdit::~PrintEdit() { cout << "Вызван деструктор класса Figur\n"; };