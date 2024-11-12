#include "Poet.h"

Poet::Poet() :fio(""), Byear(0), Dyear(0) { cout << "Вызван конструктор класса Poet\n"; };
Poet::Poet(const string& f, const int& By, const int& Dy, const vector<string>& w) :fio(f), Byear(By), Dyear(Dy), works(w) {
	cout<< "Вызван конструктор c параметрами класса Poet\n"; }
Poet::Poet(const Poet& tmp) : fio(tmp.fio), Byear(tmp.Byear), Dyear(tmp.Dyear), works(tmp.works) {
	cout << "Вызван конструктор копирования класса Poet\n";
}
Poet::~Poet() { cout << "Вызван деструктор класса Poet\n"; }
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
		cout << "Проверьте введенные данные!!! Возможео вы допустили ошибку.";
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
	cout << "Поэт: " << this->fio << endl;
	cout << "Годы жизни: " << this->Byear << " - " << this->Dyear << endl;
	cout << "Произведения: ";
	for (const auto& w : works) {
		cout << w << "; ";
	}
	cout << endl;
}
void Poet::edit_inf() {
    cout << "Редактирование информации о поэте:\n";
    cout << "1. Изменить имя\n";
    cout << "2. Изменить годы жизни\n";
    cout << "3. Изменить список произведений\n";
    cout << "0. Выйти\n";

    char choice;
    while (true) {
        choice = _getch();
        switch (choice) {
        case '1': {
            cout << "Введите новое имя: ";
            getline(cin, fio);
            cout << "Имя успешно обновлено.\n";
            break;
        }
        case '2': {
            cout << "Введите год рождения: ";
            Byear = check();
            cout << "Введите год смерти: ";
            Dyear = check();
            cout << "Годы жизни обновлены.\n";
            break;
        }
        case '3': {
            works.clear();
            cout << "Введите количество произведений: ";
            int numWorks = check();
            cout << "Введите названия произведений:\n";
            for (int i = 0; i < numWorks; ++i) {
                string work;
                cout << i + 1 << ": ";
                getline(cin, work);
                works.push_back(work);
            }
            cout << "Произведения обновлены.\n";
            break;
        }
        case '0':
            cout << "Выход из редактирования\n";
            return;
        default:
            cout << "Неверная команда.\n";
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
    while (getline(ss, work, ',')) {  // Работы разделены запятыми
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
        if (i != works.size() - 1) out << ',';  // Запятая между работами
    }
    out << "\n";
    out << fio;
    out << '\n';
}