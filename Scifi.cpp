#include "Scifi.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

// Конструктор по умолчанию
Scifi::Scifi() : fio(""), moviesAdapted(false) {
    std::cout << "Вызван конструктор класса Scifi\n";
}

// Конструктор с параметрами
Scifi::Scifi(const std::string& f, const std::vector<std::string>& w, bool adapted)
    : fio(f), works(w), moviesAdapted(adapted) {
    std::cout << "Вызван конструктор с параметрами класса Scifi\n";
}

// Конструктор копирования
Scifi::Scifi(const Scifi& tmp)
    : fio(tmp.fio), works(tmp.works), moviesAdapted(tmp.moviesAdapted) {
    std::cout << "Вызван конструктор копирования класса Scifi\n";
}

// Деструктор
Scifi::~Scifi() {
    std::cout << "Вызван деструктор класса Scifi\n";
}

// Методы для установки значений
void Scifi::set_FScifi(const std::string& f) {
    this->fio = f;
}

void Scifi::set_WScifi(const std::vector<std::string>& w) {
    this->works = w;
}

void Scifi::set_MoviesAdapted(bool adapted) {
    this->moviesAdapted = adapted;
}

// Методы для получения значений
std::string Scifi::get_FScifi() const {
    return this->fio;
}

std::vector<std::string> Scifi::get_WScifi() const {
    return this->works;
}

bool Scifi::get_MoviesAdapted() const {
    return this->moviesAdapted;
}

// Метод для вывода информации о фантасте
void Scifi::print() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Научный фантаст: " << this->fio << std::endl;
    std::cout << "Произведения: ";
    for (const auto& work : works) {
        std::cout << work << "; ";
    }
    std::cout << "\nЭкранизации: " << (moviesAdapted ? "Да" : "Нет") << std::endl;
}

// Метод для редактирования информации о фантасте
void Scifi::edit_inf() {
    std::cout << "Редактирование информации о научном фантасте:\n";
    std::cout << "1. Изменить имя\n";
    std::cout << "2. Изменить список произведений\n";
    std::cout << "3. Изменить наличие экранизаций\n";
    std::cout << "0. Выйти\n";

    char choice;
    while (true) {
        choice = _getch();
        switch (choice) {
        case '1': {
            std::cout << "Введите новое имя: ";
            std::getline(std::cin, fio);
            std::cout << "Имя успешно обновлено.\n";
            break;
        }
        case '2': {
            works.clear();
            std::cout << "Введите количество произведений: ";
            int numWorks;
            std::cin >> numWorks;
            std::cin.ignore();
            std::cout << "Введите названия произведений:\n";
            for (int i = 0; i < numWorks; ++i) {
                std::string work;
                std::cout << i + 1 << ": ";
                std::getline(std::cin, work);
                works.push_back(work);
            }
            std::cout << "Произведения обновлены.\n";
            break;
        }
        case '3': {
            std::cout << "Были ли сняты фильмы по книгам (1 - Да, 0 - Нет): ";
            int adapted;
            std::cin >> adapted;
            moviesAdapted = adapted == 1;
            std::cout << "Статус экранизаций обновлен.\n";
            break;
        }
        case '0':
            std::cout << "Выход из редактирования\n";
            return;
        default:
            std::cout << "Неверная команда.\n";
            break;
        }
    }
}