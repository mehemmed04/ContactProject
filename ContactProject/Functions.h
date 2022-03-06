#pragma once

#include<iostream>
using namespace std;
#include "Entities.h"

void ShowHuman(const Human& human) {
	cout << "Name : " << human.name << endl;
	cout << "Phone : " << human.phonenumber << endl;
	cout << "Create Date : " << human.createdDate << endl;
}

void ShowAll(const Contact& contact) {
	for (size_t i = 0; i < contact.count; i++)
	{
		ShowHuman(*contact.humans[i]);
		cout << endl;
	}
}

Human* GetNewHuman() {
	char* name = new char[100]{};
	cin.ignore();
	cin.clear();
	cout << "Enter name : " << endl;
	cin.getline(name, 100);

	char* number = new char[100]{};
	cout << "Enter number : " << endl;
	cin.getline(number, 100);

	Human* human = new Human{ name,number,__DATE__ };
	return human;
}
void AddNewHuman(Contact& contact, const Human& human) {
	int count = contact.count;
	auto newhumans = new Human * [count + 1]{};
	for (size_t i = 0; i < count; i++)
	{
		newhumans[i] = contact.humans[i];
	}
	newhumans[count] = new Human{ human };
	contact.humans = newhumans;
	newhumans = NULL;
	contact.count++;
	cout << "New contact added successfully" << endl;
}

int GetDeletedAccountID() {
	int id = 0;
	cout << "Enter ID : ";
	cin >> id;
	return id;
}

void DeleteContact(Contact& contact) {
	int id = GetDeletedAccountID();
	int count = contact.count;
	auto newhumans = new Human * [count - 1];
	int index = 0;
	for (size_t i = 0; i < id-1; i++,index++)
	{
		newhumans[index] = contact.humans[i];
	}
	for (size_t i = id; i < count; i++,index++)
	{
		newhumans[index] = contact.humans[i];
	}
	contact.humans = newhumans;
	newhumans = NULL;
	contact.count--;

}

char* GetSearchKeyWord() {
	cout << "Search : ";
	char* text = new char[100]{};
	cin.ignore();
	cin.clear();
	cin.getline(text, 100);
	return text;

}

char ToLower(char ch) {
	if ((int)ch >= 65 && (int)ch <= 90) {
		ch = ch + 32;
	}
	return ch;
}

void SearchContact(Contact& contact,char* searchword) {
	int l_searchword = strlen(searchword);
	bool HasFound = false;
	for (size_t i = 0; i < contact.count; i++)
	{
		int counter = 0;
		int l_name = strlen(contact.humans[i]->name);
		for (size_t k = 0; k < l_searchword; k++)
		{
			for (size_t y = 0; y < l_name; y++)
			{
				if (ToLower(searchword[k]) == ToLower(contact.humans[i]->name[y])) {
					counter++;
					break;
				}
			}
		}
		if (counter == l_searchword) {
			HasFound = true;
			ShowHuman(*contact.humans[i]);
			cout << endl;
		}
	}
	if (!HasFound) {
		cout << "There is not such human in contact.";
	}

	
}



void SortAToZ(Contact& contact, bool reverse = false) {
	int data = 1;
	if (reverse) {
		data = -1;
	}
		for (size_t i = 0; i < contact.count - 1; i++)
		{
			for (size_t k = 0; k < contact.count - i - 1; k++)
			{
				if (strcmp(contact.humans[k]->name, contact.humans[k + 1]->name) == data) {
					auto temp = contact.humans[k];
					contact.humans[k] = contact.humans[k + 1];
					contact.humans[k + 1] = temp;
				}
			}
		}

}



