#pragma once
#include "PrintEdit.h"
#include <vector>
#include <string>

class Scifi : public PrintEdit {
private:
    string fio;                // ��� ������
    vector<string> works; // �������� ������������
    bool moviesAdapted;             // ������� ������� �����������

public:
    // ������������ � ����������
    Scifi();
    Scifi(const string& f, const vector<std::string>& w, bool adapted);
    Scifi(const Scifi& tmp);
    ~Scifi();

    // ������ ��� ��������� ��������
    void set_FScifi(const string& f);
    void set_WScifi(const vector<string>& w);
    void set_MoviesAdapted(bool adapted);

    // ������ ��� ��������� ��������
    string get_FScifi() const;
    vector<string> get_WScifi() const;
    bool get_MoviesAdapted() const;

    // ��������������� ����������� �������
    void print() override;
    void edit_inf() override;
    void load_from_file(istream& in) override;
    void save_to_file(ostream& out) override;
};