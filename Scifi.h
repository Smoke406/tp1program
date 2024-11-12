#pragma once
#include "PrintEdit.h"
#include <vector>
#include <string>

class Scifi : public PrintEdit {
private:
    string fio;                // ФИО автора
    vector<string> works; // Основные произведения
    bool moviesAdapted;             // Признак наличия экранизаций

public:
    // Конструкторы и деструктор
    Scifi();
    Scifi(const string& f, const vector<std::string>& w, bool adapted);
    Scifi(const Scifi& tmp);
    ~Scifi();

    // Методы для установки значений
    void set_FScifi(const string& f);
    void set_WScifi(const vector<string>& w);
    void set_MoviesAdapted(bool adapted);

    // Методы для получения значений
    string get_FScifi() const;
    vector<string> get_WScifi() const;
    bool get_MoviesAdapted() const;

    // Переопределение виртуальных методов
    void print() override;
    void edit_inf() override;
    void load_from_file(istream& in) override;
    void save_to_file(ostream& out) override;
};