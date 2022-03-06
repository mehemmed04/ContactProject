#pragma once

#include<iostream>
#include "Entities.h"
#include "Functions.h"
using namespace std;


void ShowMenu() {
	cout << "Show All Contacts  1" << endl;
	cout << "Add New Contact    2" << endl;
	cout << "Delete Contact     3" << endl;
	cout << "Search Contact     4" << endl;
	cout << "Show Contact A-Z   5" << endl;
	cout << "Show Contact Z-A   6" << endl;
}


void Start() {
	Human* h1 = new Human{
		new char[] {"Elchin"},
		new char[] {"+994 55 211 11 11"},
		__DATE__
	};

	Human* h2 = new Human{
		new char[] {"Akif"},
		new char[] {"+994 55 256 87 94"},
		__DATE__
	};

	Human* h3 = new Human{
		new char[] {"John"},
		new char[] {"+2564 111 001 26 94"},
		__DATE__
	};

	Human* h4 = new Human{
		new char[] {"Tural"},
		new char[] {"+7894 11 1 2 11"},
		__DATE__
	};

	auto humans = new Human * [] {h1, h2, h3, h4};
	Contact* contact = new Contact{ humans,4 };

	while (true)
	{
		ShowMenu();
		int select = 0;
		cout << "ENTER SELECT : " << endl;
		cin >> select;
		system("cls");
		if (select == 1) {
			ShowAll(*contact);
		}
		else if (select == 2) {
			auto newhuman = GetNewHuman();
			AddNewHuman(*contact,*newhuman);
			SortAToZ(*contact);
		}
		else if (select == 3) {
			DeleteContact(*contact);
			cout << "Deleted successfully" << endl;
		}
		else if (select == 4) {
			char* searchword = GetSearchKeyWord();
			SearchContact(*contact,searchword);
		}
		else if (select == 5) {
			SortAToZ(*contact);	
			ShowAll(*contact);
		}
		else if (select == 6) {
			SortAToZ(*contact,true);
			ShowAll(*contact);
		}
	}


}