#include "Novelist.h"
// Конструктор по умолчанию
Novelist::Novelist() : fio(""), Byear(0), Dyear(0), bio("") {
    std::cout << "Вызван конструктор класса Novelist\n";
}

// Конструктор с параметрами
Novelist::Novelist(const std::string& f, const int& By, const int& Dy, const vector<string>& w, const std::string& b) : fio(f), Byear(By), Dyear(Dy),works(w), bio(b) {
   // works.push_back(w);
    std::cout << "Вызван конструктор с параметрами класса Novelist\n";
}

// Конструктор копирования
Novelist::Novelist(const Novelist& tmp)
    : fio(tmp.fio), Byear(tmp.Byear), Dyear(tmp.Dyear), works(tmp.works), bio(tmp.bio) {
    std::cout << "Вызван конструктор копирования класса Novelist\n";
}

// Деструктор
Novelist::~Novelist() {
    std::cout << "Вызван деструктор класса Novelist\n";
}

// Методы для установки значений
void Novelist::set_FNovel(std::string f) {
    this->fio = f;
}

void Novelist::set_BDNovel(int By, int Dy) {
    if (By < Dy) {
        this->Byear = By;
        this->Dyear = Dy;
    }
    else {
        std::cout << "Некорректные данные: год рождения должен быть меньше года смерти.\n";
    }
}

void Novelist::set_WNovel(vector<string> w) {
    this->works = w;
}

void Novelist::set_bNovel(std::string b) {
    this->bio = b;
}

// Методы для получения значений
std::string Novelist::get_FNovel() {
    return this->fio;
}

int* Novelist::get_BDNovel() {
    int* BD = new int[2] { Byear, Dyear };
    return BD;
}

std::string Novelist::get_WNovelt() {
    if (!works.empty()) return works.front();
    return "Нет произведений";
}

std::string Novelist::get_bNovel() {
    return this->bio;
}

// Переопределение метода print для вывода информации о романисте
void Novelist::print() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Романист: " << fio << std::endl;
    std::cout << "Годы жизни: " << Byear << " - " << Dyear << std::endl;
    std::cout << "Произведения: ";
    for (const auto& work : works) {
        std::cout << work << "; ";
    }
    std::cout << "\nБиография: " << bio << std::endl;
}

// Переопределение метода edit_inf для редактирования информации о романисте
void Novelist::edit_inf() {
    std::cout << "Редактирование информации о романисте:\n";
    std::cout << "1. Изменить имя\n";
    std::cout << "2. Изменить годы жизни\n";
    std::cout << "3. Изменить список произведений\n";
    std::cout << "4. Изменить биографию\n";
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
            std::cout << "Введите год рождения: ";
            Byear = check();
            std::cout << "Введите год смерти: ";
            Dyear = check();
            std::cout << "Годы жизни обновлены.\n";
            break;
        }
        case '3': {
            works.clear();
            std::cout << "Введите количество произведений: ";
            int numWorks = check();
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
        case '4': {
            std::cout << "Введите новую биографию: ";
            std::getline(std::cin, bio);
            std::cout << "Биография успешно обновлена.\n";
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
void Novelist::load_from_file(istream& in) {
    //getline(in, fio);
    in >> Byear >> Dyear;
    //getline(in, bio);
    //in.ignore();  // Игнорируем символ новой строки после Dyear
    string works_line;
    getline(in, works_line);
    works.clear();
    stringstream ss(works_line);
    string work;
    while (getline(ss, work, ',')) {  // Работы разделены запятыми
        works.push_back(work);
    }
    getline(in, fio);
    getline(in, bio);
}

void Novelist::save_to_file(ostream& out) {
    out << "Novelist\n";
    out << Byear << ' ' << Dyear;
    for (size_t i = 0; i < works.size(); ++i) {
        out << works[i];
        if (i != works.size() - 1) out << ',';  // Запятая между работами
    }
    out << '\n';
    out << fio << '\n';
    out << bio << '\n';
}