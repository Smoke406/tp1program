#include "Scifi.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

// ����������� �� ���������
Scifi::Scifi() : fio(""), moviesAdapted(false) {
    std::cout << "������ ����������� ������ Scifi\n";
}

// ����������� � �����������
Scifi::Scifi(const std::string& f, const std::vector<std::string>& w, bool adapted)
    : fio(f), works(w), moviesAdapted(adapted) {
    std::cout << "������ ����������� � ����������� ������ Scifi\n";
}

// ����������� �����������
Scifi::Scifi(const Scifi& tmp)
    : fio(tmp.fio), works(tmp.works), moviesAdapted(tmp.moviesAdapted) {
    std::cout << "������ ����������� ����������� ������ Scifi\n";
}

// ����������
Scifi::~Scifi() {
    std::cout << "������ ���������� ������ Scifi\n";
}

// ������ ��� ��������� ��������
void Scifi::set_FScifi(const std::string& f) {
    this->fio = f;
}

void Scifi::set_WScifi(const std::vector<std::string>& w) {
    this->works = w;
}

void Scifi::set_MoviesAdapted(bool adapted) {
    this->moviesAdapted = adapted;
}

// ������ ��� ��������� ��������
std::string Scifi::get_FScifi() const {
    return this->fio;
}

std::vector<std::string> Scifi::get_WScifi() const {
    return this->works;
}

bool Scifi::get_MoviesAdapted() const {
    return this->moviesAdapted;
}

// ����� ��� ������ ���������� � ��������
void Scifi::print() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "������� �������: " << this->fio << std::endl;
    std::cout << "������������: ";
    for (const auto& work : works) {
        std::cout << work << "; ";
    }
    std::cout << "\n�����������: " << (moviesAdapted ? "��" : "���") << std::endl;
}

// ����� ��� �������������� ���������� � ��������
void Scifi::edit_inf() {
    std::cout << "�������������� ���������� � ������� ��������:\n";
    std::cout << "1. �������� ���\n";
    std::cout << "2. �������� ������ ������������\n";
    std::cout << "3. �������� ������� �����������\n";
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
            works.clear();
            std::cout << "������� ���������� ������������: ";
            int numWorks;
            std::cin >> numWorks;
            std::cin.ignore();
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
        case '3': {
            std::cout << "���� �� ����� ������ �� ������ (1 - ��, 0 - ���): ";
            int adapted;
            std::cin >> adapted;
            moviesAdapted = adapted == 1;
            std::cout << "������ ����������� ��������.\n";
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