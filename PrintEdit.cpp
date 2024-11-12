#include "PrintEdit.h"
PrintEdit::PrintEdit() { cout << "Вызван конструктор класса PrintEdit\n"; };
PrintEdit::PrintEdit(const int& n) { cout << "Вызван конструктор c параметрами класса PrintEdit\n"; }
PrintEdit::PrintEdit(const PrintEdit& n) { cout << "Вызван конструктор копирования класса PrintEdit\n"; };
PrintEdit::~PrintEdit() { cout << "Вызван деструктор класса PrintEdit\n"; };