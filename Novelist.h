#pragma once
#include "PrintEdit.h"
#include <iostream>
#include <conio.h>
#include "check.h"
#include <Windows.h>
#include <sstream>
class Novelist : public PrintEdit {
private:
	string fio;
	int Byear;
	int Dyear;
	vector<string> works;
	string bio;
public:
	Novelist();
	Novelist(const string& f, const int& By, const int& Dy, const vector<string>& w, const string& b);
	Novelist(const Novelist& tmp);
	~Novelist();

	void set_FNovel(string f);
	void set_BDNovel(int By, int Dy);
	void set_WNovel(vector<string> w);
	void set_bNovel(string b);

	string get_FNovel();
	int* get_BDNovel();
	string get_WNovelt();
	string get_bNovel();

	void print() override;
	void edit_inf() override;
	void load_from_file(istream& in) override;
	void save_to_file(ostream& out) override;
};