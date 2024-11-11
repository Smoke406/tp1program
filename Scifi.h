#pragma once
#include "PrintEdit.h"
#include <vector>
#include <string>

class Scifi : public PrintEdit {
private:
    std::string fio;                // ��� ������
    std::vector<std::string> works; // �������� ������������
    bool moviesAdapted;             // ������� ������� �����������

public:
    // ������������ � ����������
    Scifi();
    Scifi(const std::string& f, const std::vector<std::string>& w, bool adapted);
    Scifi(const Scifi& tmp);
    ~Scifi();

    // ������ ��� ��������� ��������
    void set_FScifi(const std::string& f);
    void set_WScifi(const std::vector<std::string>& w);
    void set_MoviesAdapted(bool adapted);

    // ������ ��� ��������� ��������
    std::string get_FScifi() const;
    std::vector<std::string> get_WScifi() const;
    bool get_MoviesAdapted() const;

    // ��������������� ����������� �������
    void print() override;
    void edit_inf() override;
};