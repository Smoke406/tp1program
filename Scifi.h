#pragma once
#include "PrintEdit.h"
#include <vector>
#include <string>

class Scifi : public PrintEdit {
private:
    std::string fio;                // ФИО автора
    std::vector<std::string> works; // Основные произведения
    bool moviesAdapted;             // Признак наличия экранизаций

public:
    // Конструкторы и деструктор
    Scifi();
    Scifi(const std::string& f, const std::vector<std::string>& w, bool adapted);
    Scifi(const Scifi& tmp);
    ~Scifi();

    // Методы для установки значений
    void set_FScifi(const std::string& f);
    void set_WScifi(const std::vector<std::string>& w);
    void set_MoviesAdapted(bool adapted);

    // Методы для получения значений
    std::string get_FScifi() const;
    std::vector<std::string> get_WScifi() const;
    bool get_MoviesAdapted() const;

    // Переопределение виртуальных методов
    void print() override;
    void edit_inf() override;
};