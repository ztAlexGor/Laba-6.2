#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

class Event {//class that hold all information about event
	int date;
	double cost;
	std::string conditions;
public:
	Event(int date, double cost, std::string conditions);
	int GetDate();
	double GetCost();
	std::string GetConditions();
};

class OffersList {//list of availible events
	int count;
	std::vector<Event> events;
public:
	OffersList();
	void Print();
	int AddEvent(Event ev);
	bool DelEvent(int num);
	int SearchEvent();
	void NewMonth();
	Event GetEvent(int num);
	bool Contain(Event ev);
	int GetCount();
};

class Parent {//class allowing parents to take part in events or look at event list
	OffersList myActivities;
public:
	void Print();
	bool TakePart(Event ev);
	bool DelEvent(int num);
	bool Contain(Event ev);
};

class Group {//class that holds parents accaunts and all information that refer to group events
	OffersList offers;
	std::vector<Parent> parents;
public:
	Group(int count);
	void Print();
	void PrintActivities(int num);
	int AddEvent(Event ev);
	bool TakePart(int Nomer, int num);
	bool DelEvent(int num);
	int SearchEvent();
	void PrintMembers();
};

void interface(Group*);
void organizers(Group*);
void parents(Group*, int num);
int ChildName(std::string name);
void InputTests(Group* gr);