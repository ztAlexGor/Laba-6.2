#include "Header.h"

using namespace std;

enum Child_names {//имена детей в группе
    Alex, Olga, Dasha, Egor, Dima, Pasha
};

int main(){
    setlocale(LC_ALL, "rus");
    Group group1(6);//Группа из 6-ти детей
    InputTests(&group1);//несколько тестовых наборов
    interface(&group1);//через данную функцию осущестляеться взаимодействие с пользователями
}



void interface(Group* group) {//можно работать под видом организатора мероприятия а можно под видом родителя
    cout << "Горобец Александр студент гр. ИП-96\nВариант №5 уровень сложность: В\n";
    _getch();
    system("cls");
    char p;
    bool u = true;

    while (u) {
        cout << "Нажмите 0 если хотите закончить программу\nНажмите 1 если хотите работать от лица родителя\nНажмите 2 если хотите работать как организатор мероприятий\nНажмите 3 если хотите посмотреть статистику" << endl;
        p = _getch();
        system("cls");
        if (p == '0')u = false;
        else if (p == '1') {
            string name;
            cout << "Введите имя вашего ребёнка (Доступно: Alex, Olga, Dasha, Egor, Dima, Pasha)" << endl;
            cin >> name;
            if (!ChildName(name)) {
                cout << "Имени нет в списке" << endl;
                _getch();
            }
            else {
                system("cls");
                parents(group, ChildName(name));
            }
        }
        else if (p == '2') {
            organizers(group);
        }
        else if (p == '3') {//Показывает сведения о участвующих в каждом мероприятии и общую стоимость всего этого
            group->PrintMembers();
            _getch();
        }
    }
}

void organizers(Group* group) {//Здець вы можете добавить либо удалить мероприятие или посмотреть список активных событий
    char p;
    bool u = true;

    while (u) {
        cout << "Нажмите 0 если хотите выйти из данного режима роботы\nНажмите 1 если хотите посмотреть список мероприятий\nНажмите 2 если хотите добавить мероприятие\nНажмите 3 если хотите удалить мероприятие" << endl;
        p = _getch();
        system("cls");
        if (p == '0')u = false;
        else if (p == '1') {
            group->Print();
            _getch();
            system("cls");
        }
        else if (p == '2') {
            int day;
            double cost;
            string details;
            cout<<"Введите информацию о мероприятии" << endl;
            while (details == "")getline(cin, details);
            cout << "Введите дату проведения мероприятия" << endl;
            cin >> day;
            cout << "Введите стоимость участия в мероприятии" << endl;
            cin >> cost;
            cout << "Номер вашего мероприятия: " << group->AddEvent(Event(day, cost, details)) << endl;
            _getch();
            system("cls");
        }
        else if (p == '3') {
            int number;
            cout << "Введите номер мероприятия" << endl;
            cin >> number;
            if (group->DelEvent(number - 1)) {
                cout << "Мероприятие под номером " << number << " удалено" << endl;
            }
            else cout << "Неверный номер мероприятия" << endl;
            _getch();
            system("cls");
        }
        
    }
}


//Сюда вы попадаете как конкретный родитель по имени своего ребёнка
//и можете сдесь посмотреть в каких активностях участвует ваш ребёнок или записаться на одну из них
void parents(Group* group, int num) {
    char p;
    bool u = true;

    while (u) {
        cout << "Нажмите 0 если хотите выйти из данного режима роботы\nНажмите 1 если хотите посмотреть список доступных мероприятий\nНажмите 2 если хотите посмотреть список ваших мероприятий\nНажмите 3 если хотите записаться на мероприятие" << endl;
        p = _getch();
        system("cls");
        if (p == '0')u = false;
        else if (p == '1') {
            group->Print();
            _getch();
            system("cls");
        }
        else if (p == '2') {
            group->PrintActivities(num);
            _getch();
            system("cls");
        }
        else if (p == '3') {
            int number;
            cout << "Введите номер мероприятия в котором хотите участвовать" << endl;
            cin >> number;
            system("cls");
            if (group->TakePart(number, num -1)) {
                cout << "Теперь вы принимаете участие в мероприятии под номером " << number << endl;
            }
            else cout << "Неверный номер мероприятия" << endl;
            _getch();
            system("cls");
        }

    }
}

int ChildName(string name) {
    if (name == "Alex")return 1;
    else if (name == "Olga")return 2;
    else if (name == "Dasha")return 3;
    else if (name == "Egor")return 4;
    else if (name == "Dima")return 5;
    else if (name == "Pasha")return 6;
    return 0;
}

void InputTests(Group* gr) {
    gr->AddEvent(Event(21, 345, "First activity"));
    gr->AddEvent(Event(11, 84, "Second activity"));
    gr->AddEvent(Event(3, 33, "Park"));
    gr->AddEvent(Event(9, 100, "City tour"));
    gr->AddEvent(Event(6, 500, "Theatre"));
    gr->TakePart(1, 1);
    gr->TakePart(2, 1);
    gr->TakePart(4, 1);
    gr->TakePart(1, 2);
    gr->TakePart(4, 2);
    gr->TakePart(1, 3);
    gr->TakePart(3, 5);
}

string Names(int n) {
    switch (n) {
    case 0: return "Alex";
    case 1: return "Olga";
    case 2: return "Dasha";
    case 3: return "Egor";
    case 4: return "Dima";
    case 5: return "Pasha";
    }
}

int Event::GetDate(){
    return date;
}
double Event::GetCost(){
    return cost;
}
string Event::GetConditions(){
    return conditions;
}
Event::Event(int date, double cost, std::string conditions) : date(date), cost(cost), conditions(conditions) {}


void Parent::Print(){
    myActivities.Print();
}

bool Parent::TakePart(Event ev){
    return myActivities.AddEvent(ev);
}

bool Parent::DelEvent(int num){
    return DelEvent(num);
}

bool Parent::Contain(Event ev){
    if (myActivities.Contain(ev))return true;
    else return false;
}


OffersList::OffersList(){
    count = 0;
}
void OffersList::Print(){
    if (count == 0)cout << "Нет запланированных мероприятий" << endl;
    for (int i = 0; i < events.size(); i++) {
        cout << "Мероприятие номер " << i + 1 << endl << "Детали: " << events[i].GetConditions() << endl << "Дата проведения: " << events[i].GetDate() << endl << "Цена: " << events[i].GetCost() << endl << endl;
    }
}

int OffersList::AddEvent(Event ev){
    events.push_back(ev);
    count++;
    return count;
}
bool OffersList::DelEvent(int num){
    if (num >= 0 && num <= count) {
        events.erase(events.begin() + num);
        count--;
        return 1;
    }
    else return 0;
}
int OffersList::SearchEvent(){
    return 0;
}
void OffersList::NewMonth(){
    events.clear();
}

Event OffersList::GetEvent(int num){
    if (num > 0 && num <= events.size())return events[num - 1];
}

bool OffersList::Contain(Event ev){
    for (auto i : events) {
        if (i.GetConditions() == ev.GetConditions() && i.GetCost() == ev.GetCost() && i.GetDate() == ev.GetDate())return true;
    }
    return false;
}

int OffersList::GetCount(){
    return count;
}


Group::Group(int count){
    for (int i = 0; i < count; i++) {
        parents.push_back(Parent{});
    }
}

void Group::Print(){
    offers.Print();
}

void Group::PrintActivities(int num){
    parents[num - 1].Print();
}

int Group::AddEvent(Event ev){
    return offers.AddEvent(ev);
}

bool Group::TakePart(int Nomer, int num){
    if (Nomer > 0 && parents[num].TakePart(offers.GetEvent(Nomer)))return true;
    else return false;
}

bool Group::DelEvent(int num){
    return offers.DelEvent(num);
}

int Group::SearchEvent(){
    return offers.SearchEvent();
}

void Group::PrintMembers(){
    for (int num = 1; num <= offers.GetCount(); num++) {
        int summa = 0;
        Event ev = offers.GetEvent(num);
        for (auto i : parents) {
            if (i.Contain(ev))summa++;
        }
        cout << "В мероприятии № " << num << " учасвтует " << summa << " человек. Общая стоимость мероприятия: " << summa * ev.GetCost() << endl;
        for (int i = 0; i < parents.size(); i++) {
            if (parents[i].Contain(ev))cout << Names(i)<<" ";
        }
        cout << endl << endl;
    }
}
