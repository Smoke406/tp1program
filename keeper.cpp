#include "Keeper.h"
#include <iostream>
Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {}
Keeper::Keeper(Element* h, Element* t, int c) : head(h), tail(t), count(c) {}
Keeper::Keeper(const Keeper& other) : head(other.head), tail(other.tail), count(other.count) {}
Keeper::~Keeper() { delete_all(); }

Element* Keeper::get_head() { return head; }
Element* Keeper::get_tail() { return tail; }
int Keeper::get_count() { return count; }

void Keeper::delete_all() {
    while (head != nullptr) {
        Element* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
        count--;
    }
    tail = nullptr;
}

Keeper& Keeper::delete_element(int n) {
    if (n < 1 || n > count) {
        cout << "Элемента с таким индексом не существует." << endl;
        return *this;
    }
    if (n == 1) {
        --(*this); 
        return *this;
    }
    Element* temp = head;
    for (int i = 1; i < n - 1; i++) {
        temp = temp->next;
    }
    Element* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete == tail) {
        tail = temp;
    }
    delete toDelete->data;
    delete toDelete;
    count--;
    return *this;
}

Keeper& Keeper::edit_element(int n) {
    if (n < 1 || n > count) {
        cout << "Элемента с таким индексом не существует." << endl;
        return *this;
    }
    Element* tmp = head;
    for (int i = 1; i < n; i++) {
        tmp = tmp->next;
    }
    if (tmp->data) {
        tmp->data->edit_inf();
    }
    else {
        cout << "Данных у данного элемента нет." << endl;
    }
    return *this;
}

void Keeper::add_to_head(PrintEdit* item) {
    Element* new_el = new Element;
    new_el->data = item;
    new_el->next = head;
    if (head == nullptr) {
        tail = new_el;
    }
    head = new_el;
    count++;
}

void Keeper::add_to_tail(PrintEdit* item) {
    Element* new_el = new Element;
    new_el->data = item;
    new_el->next = nullptr;
    if (head == nullptr) {
        head = tail = new_el;
    }
    else {
        tail->next = new_el;
        tail = new_el;
    }
    count++;
}

Keeper& Keeper::operator++() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    string fio;
    string bio;
    bool movies;
    int Byear, Dyear;
    vector<string> proizved;
    cout << "Выберите тип для добавления: 1 - Поэт, 2 - Романист, 3 - Фантаст" << endl;
    cin >> choice;
    cin.ignore();
    if (choice == 1) {
       
        cout << "Введите имя поэта: ";
        getline(cin, fio);
        cout << "Введите год рождения: ";
        Byear = check();
        cout << "Введите год смерти: ";
        Dyear = check();
        cout << "Введите количество произведений: ";
        int numWorks = check();
        cout << "Введите названия произведений:\n";
        for (int i = 0; i < numWorks; ++i) {
            string work;
            cout << i + 1 << ": ";
            getline(cin, work);
            proizved.push_back(work);
        }
        
        
        Poet* poet = new Poet(fio, Byear, Dyear, proizved);
        add_to_head(poet);
        cout << "Новый элемент успешно добавлен в начало списка" << endl;
    }
    else if (choice == 2) {
        
        
        cout << "Введите имя Романиста: ";
        getline(cin, fio);
        cout << "Введите год рождения: ";
        Byear = check();
        cout << "Введите год смерти: ";
        Dyear = check();
        cout << "Введите количество произведений: ";
        int numWorks = check();
        cout << "Введите названия произведений:\n";
        for (int i = 0; i < numWorks; ++i) {
            string work;
            cout << i + 1 << ": ";
            getline(cin, work);
            proizved.push_back(work);
        }
        cout << "Введите краткую биографию: ";
        getline(cin, bio);
        
        Novelist* novelist = new Novelist(fio, Byear, Dyear, proizved, bio);
        add_to_head(novelist);
        cout << "Новый элемент успешно добавлен в начало списка" << endl;
        
    }
    else if (choice == 3)
    {
        cout << "Введите имя Фантаста: ";
        getline(cin, fio);
        cout << "Введите количество произведений: ";
        int numWorks = check();
        cout << "Введите названия произведений:\n";
        for (int i = 0; i < numWorks; ++i) {
            string work;
            cout << i + 1 << ": ";
            getline(cin, work);
            proizved.push_back(work);
        }
        std::cout << "Были ли сняты фильмы по книгам (1 - Да, 0 - Нет): ";
        int adapted;
        std::cin >> adapted;
        movies = adapted == 1;
        

        Scifi* scifi = new Scifi(fio, proizved, movies);
        add_to_head(scifi);
        cout << "Новый элемент успешно добавлен в начало списка" << endl;
    }
    return *this;
}

Keeper& operator++(Keeper& K, int) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string fio;
    string bio;
    bool movies;
    int Byear, Dyear;
    vector<string> proizved;
    int choice;
    cout << "Выберите тип для добавления: 1 - Поэт, 2 - Романист, 3 - Фантаст" << endl;
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Введите имя поэта: ";
        getline(cin, fio);
        cout << "Введите год рождения: ";
        Byear = check();
        cout << "Введите год смерти: ";
        Dyear = check();
        cout << "Введите количество произведений: ";
        int numWorks = check();
        cout << "Введите названия произведений:\n";
        for (int i = 0; i < numWorks; ++i) {
            string work;
            cout << i + 1 << ": ";
            getline(cin, work);
            proizved.push_back(work);
        }
        Poet* poet = new Poet(fio, Byear, Dyear, proizved);
        K.add_to_tail(poet);
        cout << "Новый элемент успешно добавлен в конец списка" << endl;
    }
    else if (choice == 2) {
        cout << "Введите имя Романиста: ";
        getline(cin, fio);
        cout << "Введите год рождения: ";
        Byear = check();
        cout << "Введите год смерти: ";
        Dyear = check();
        cout << "Введите количество произведений: ";
        int numWorks = check();
        cout << "Введите названия произведений:\n";
        for (int i = 0; i < numWorks; ++i) {
            string work;
            cout << i + 1 << ": ";
            getline(cin, work);
            proizved.push_back(work);
        }
        cout << "Введите краткую биографию: ";
        getline(cin, bio);

        Novelist* novelist = new Novelist(fio, Byear, Dyear, proizved, bio);
        K.add_to_tail(novelist);
        cout << "Новый элемент успешно добавлен в конец списка" << endl;
    }
    else if (choice == 3) {
        cout << "Введите имя Фантаста: ";
        getline(cin, fio);
        cout << "Введите количество произведений: ";
        int numWorks = check();
        cout << "Введите названия произведений:\n";
        for (int i = 0; i < numWorks; ++i) {
            string work;
            cout << i + 1 << ": ";
            getline(cin, work);
            proizved.push_back(work);
        }
        std::cout << "Были ли сняты фильмы по книгам (1 - Да, 0 - Нет): ";
        int adapted;
        std::cin >> adapted;
        movies = adapted == 1;


        Scifi* scifi = new Scifi(fio, proizved, movies);
        K.add_to_tail(scifi);
        cout << "Новый элемент успешно добавлен в конец списка" << endl;
    }
    return K;
}

Keeper& Keeper::operator--(int) {
    if (count == 0) {
        cout << "Контейнер пуст." << endl;
        return *this;
    }
    Element* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    delete tail->data;
    delete tail;
    tail = temp;
    tail->next = nullptr;
    count--;
    return *this;
}

Keeper& operator--(Keeper& K) {
    if (K.count == 0) {
        cout << "Контейнер пуст." << endl;
        return K;
    }
    Element* temp = K.head;
    K.head = K.head->next;
    delete temp->data;
    delete temp;
    K.count--;
    return K;
}

void Keeper::print_keeper() {
    Element* temp = head;
    if (count == 0) {
        cout << "Контейнер пуст." << endl;
        return;
    }
    int i = 0;
    while (temp != 0) {
        cout << i + 1 << " - ";
        if (temp->data) {
            temp->data->print();
        }
        else {
            cout << "Контейнер пуст.";
        }
        cout << " " << endl;;
        temp = temp->next;
        i++;
    }
}

void Keeper::print_element(int n) {
    if (n < 1 || n > count) {
        cout << "Элемента с таким индексом не существует." << endl;
        return;
    }
    Element* tmp = head;
    for (int i = 1; i < n; i++) {
        tmp = tmp->next;
    }
    tmp->data->print();
}

void Keeper::load_from_file(const string& filename) {
    ifstream in(filename);
    int c = 0;
    string type;
    if (!in) {
        cerr << "Ошибка открытия файла для загрузки!" << endl;
        return;
    }
    while (in >> type) {
        PrintEdit* item = nullptr;
        if (type == "Poet") {
            item = new Poet();
        }
        else if (type == "Novelist") {
            item = new Novelist();
        }
        else if (type == "Scifi")
        {
            item = new Scifi();
        }
        if (item) {
            item->load_from_file(in);
            c += 1;
            this->add_to_tail(item);
        }
    }
    in.close();
    cout << "В контейнер добавлено " << c << " объектов." << endl;
}

void Keeper::save_to_file(const string& filename) {
    ofstream out(filename);
    Element* current = head;
    while (current != nullptr) {
        current->data->save_to_file(out);
        current = current->next;
    }
    cout << "Данные сохранены." << endl;
}
