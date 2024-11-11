#pragma once
#include "PrintEdit.h"

class Poet : public PrintEdit {
private:
	string fio;
	int Byear;
	int Dyear;
	vector<string> works;
public:
	Poet();
	Poet(const string& f, const int& By, const int& Dy, const vector<string>& w);
	Poet(const Poet& tmp);
	~Poet();

	void set_FPoet(string f);
	void set_BDPoet(int By, int Dy);
	void set_WPoet(vector<string>& w);

	string get_FPoet();
	int* get_BDPoet();
	vector<string> get_WPoet();

	void print() override;
	void edit_inf() override;
};