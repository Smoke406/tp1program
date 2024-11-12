#include "Poet.h"

Poet::Poet() :fio(""), Byear(0), Dyear(0) { cout << "������ ����������� ������ Poet\n"; };
Poet::Poet(const string& f, const int& By, const int& Dy, const vector<string>& w) :fio(f), Byear(By), Dyear(Dy), works(w) {
	cout<< "������ ����������� c ����������� ������ Poet\n"; }
Poet::Poet(const Poet& tmp) : fio(tmp.fio), Byear(tmp.Byear), Dyear(tmp.Dyear), works(tmp.works) {
	cout << "������ ����������� ����������� ������ Poet\n";
}
Poet::~Poet() { cout << "������ ���������� ������ Poet\n"; }
void Poet::set_FPoet(string f) {
	this->fio = f;
}
void Poet::set_BDPoet(int By, int Dy) {
	if ((By < Dy)&&((By+112)<Dy))
	{
		this->Byear = By;
		this->Dyear = Dy;
	}
	else
	{
		cout << "��������� ��������� ������!!! �������� �� ��������� ������.";
	}
}
void Poet::set_WPoet(vector<string>& w)
{
	this->works = w;
}
string Poet::get_FPoet()
{
	return this->fio;
}
int* Poet::get_BDPoet()
{
	int* BD = new int[2];
	BD[0] = this->Byear;
	BD[1] = this->Dyear;
	return BD;
}
vector<string> Poet::get_WPoet()
{
	return this->works;
}
void Poet::print() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "����: " << this->fio << endl;
	cout << "���� �����: " << this->Byear << " - " << this->Dyear << endl;
	cout << "������������: ";
	for (const auto& w : works) {
		cout << w << "; ";
	}
	cout << endl;
}
void Poet::edit_inf() {
    cout << "�������������� ���������� � �����:\n";
    cout << "1. �������� ���\n";
    cout << "2. �������� ���� �����\n";
    cout << "3. �������� ������ ������������\n";
    cout << "0. �����\n";

    char choice;
    while (true) {
        choice = _getch();
        switch (choice) {
        case '1': {
            cout << "������� ����� ���: ";
            getline(cin, fio);
            cout << "��� ������� ���������.\n";
            break;
        }
        case '2': {
            cout << "������� ��� ��������: ";
            Byear = check();
            cout << "������� ��� ������: ";
            Dyear = check();
            cout << "���� ����� ���������.\n";
            break;
        }
        case '3': {
            works.clear();
            cout << "������� ���������� ������������: ";
            int numWorks = check();
            cout << "������� �������� ������������:\n";
            for (int i = 0; i < numWorks; ++i) {
                string work;
                cout << i + 1 << ": ";
                getline(cin, work);
                works.push_back(work);
            }
            cout << "������������ ���������.\n";
            break;
        }
        case '0':
            cout << "����� �� ��������������\n";
            return;
        default:
            cout << "�������� �������.\n";
            break;
        }
    }
}
void Poet::load_from_file(istream& in) {
    //getline(in, fio);
    
    in >> Byear >> Dyear;
    string works_line;
    getline(in, works_line);
    works.clear();
    stringstream ss(works_line);
    string work;
    while (getline(ss, work, ',')) {  // ������ ��������� ��������
        works.push_back(work);
    }
    getline(in, fio);
}

void Poet::save_to_file(ostream& out) {
    out << "Poet\n";
    //out << fio << ':';
    out << Byear << ' ' << Dyear;
    for (size_t i = 0; i < works.size(); ++i) {
        out << works[i];
        if (i != works.size() - 1) out << ',';  // ������� ����� ��������
    }
    out << "\n";
    out << fio;
    out << '\n';
}