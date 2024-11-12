#include "Novelist.h"
// ����������� �� ���������
Novelist::Novelist() : fio(""), Byear(0), Dyear(0), bio("") {
    std::cout << "������ ����������� ������ Novelist\n";
}

// ����������� � �����������
Novelist::Novelist(const std::string& f, const int& By, const int& Dy, const vector<string>& w, const std::string& b) : fio(f), Byear(By), Dyear(Dy),works(w), bio(b) {
   // works.push_back(w);
    std::cout << "������ ����������� � ����������� ������ Novelist\n";
}

// ����������� �����������
Novelist::Novelist(const Novelist& tmp)
    : fio(tmp.fio), Byear(tmp.Byear), Dyear(tmp.Dyear), works(tmp.works), bio(tmp.bio) {
    std::cout << "������ ����������� ����������� ������ Novelist\n";
}

// ����������
Novelist::~Novelist() {
    std::cout << "������ ���������� ������ Novelist\n";
}

// ������ ��� ��������� ��������
void Novelist::set_FNovel(std::string f) {
    this->fio = f;
}

void Novelist::set_BDNovel(int By, int Dy) {
    if (By < Dy) {
        this->Byear = By;
        this->Dyear = Dy;
    }
    else {
        std::cout << "������������ ������: ��� �������� ������ ���� ������ ���� ������.\n";
    }
}

void Novelist::set_WNovel(vector<string> w) {
    this->works = w;
}

void Novelist::set_bNovel(std::string b) {
    this->bio = b;
}

// ������ ��� ��������� ��������
std::string Novelist::get_FNovel() {
    return this->fio;
}

int* Novelist::get_BDNovel() {
    int* BD = new int[2] { Byear, Dyear };
    return BD;
}

std::string Novelist::get_WNovelt() {
    if (!works.empty()) return works.front();
    return "��� ������������";
}

std::string Novelist::get_bNovel() {
    return this->bio;
}

// ��������������� ������ print ��� ������ ���������� � ���������
void Novelist::print() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "��������: " << fio << std::endl;
    std::cout << "���� �����: " << Byear << " - " << Dyear << std::endl;
    std::cout << "������������: ";
    for (const auto& work : works) {
        std::cout << work << "; ";
    }
    std::cout << "\n���������: " << bio << std::endl;
}

// ��������������� ������ edit_inf ��� �������������� ���������� � ���������
void Novelist::edit_inf() {
    std::cout << "�������������� ���������� � ���������:\n";
    std::cout << "1. �������� ���\n";
    std::cout << "2. �������� ���� �����\n";
    std::cout << "3. �������� ������ ������������\n";
    std::cout << "4. �������� ���������\n";
    std::cout << "0. �����\n";

    char choice;
    while (true) {
        choice = _getch();
        switch (choice) {
        case '1': {
            std::cout << "������� ����� ���: ";
            std::getline(std::cin, fio);
            std::cout << "��� ������� ���������.\n";
            break;
        }
        case '2': {
            std::cout << "������� ��� ��������: ";
            Byear = check();
            std::cout << "������� ��� ������: ";
            Dyear = check();
            std::cout << "���� ����� ���������.\n";
            break;
        }
        case '3': {
            works.clear();
            std::cout << "������� ���������� ������������: ";
            int numWorks = check();
            std::cout << "������� �������� ������������:\n";
            for (int i = 0; i < numWorks; ++i) {
                std::string work;
                std::cout << i + 1 << ": ";
                std::getline(std::cin, work);
                works.push_back(work);
            }
            std::cout << "������������ ���������.\n";
            break;
        }
        case '4': {
            std::cout << "������� ����� ���������: ";
            std::getline(std::cin, bio);
            std::cout << "��������� ������� ���������.\n";
            break;
        }
        case '0':
            std::cout << "����� �� ��������������\n";
            return;
        default:
            std::cout << "�������� �������.\n";
            break;
        }
    }
}
void Novelist::load_from_file(istream& in) {
    //getline(in, fio);
    in >> Byear >> Dyear;
    //getline(in, bio);
    //in.ignore();  // ���������� ������ ����� ������ ����� Dyear
    string works_line;
    getline(in, works_line);
    works.clear();
    stringstream ss(works_line);
    string work;
    while (getline(ss, work, ',')) {  // ������ ��������� ��������
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
        if (i != works.size() - 1) out << ',';  // ������� ����� ��������
    }
    out << '\n';
    out << fio << '\n';
    out << bio << '\n';
}