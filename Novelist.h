#pragma once
#include "PrintEdit.h"
class Novelist : public PrintEdit {
private:
	string fio;
	int Byear;
	int Dyear;
	vector<string> works;
	string bio;
public:
	Novelist();
	Novelist(const string& f, const int& By, const int& Dy, const string& w, const string& b);
	Novelist(const Novelist& tmp);
	~Novelist();

	void set_FNovel(string f);
	void set_BDNovel(int By, int Dy);
	void set_WNovel(string w);
	void set_bNovel(string b);

	string get_FNovel();
	int* get_BDNovel();
	string get_WNovelt();
	string get_bNovel();

	void print() override;
	void edit_inf() override;
};