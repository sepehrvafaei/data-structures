#include<iostream>
#include"hash.h"
#include<fstream>

int main() {
	hash hash1;
	hash1.AddItem("Paul", "Locha");
	hash1.AddItem("Kin", "Iced Mocha");
	hash1.AddItem("Emma", "Strawberry smoothy");
	hash1.AddItem("Annie", "HOt Chocolate");
	hash1.AddItem("Mike", "Chai Tea");
	hash1.AddItem("Joe", "Green Tea");
	hash1.PrintTable();
	hash1.PrintItemsOfIndex(0);
	hash1.FindDrink("Mike");
	hash1.FindDrink("Bob");
	hash1.RemoveItem("Joey");
	hash1.PrintTable();
	system("PAUSE");
	return 0;
}
