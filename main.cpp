#include<iostream>
#include"hash.h"
#include<fstream>

int main() {
	hash hash1;
	hash1.AddItem("Paul","Locha");
	hash1.AddItem("Kin", "Iced Mocha");
	hash1.AddItem("Emma", "Strawberry smoothy");
	hash1.AddItem("Annie", "HOt Chocolate");
	hash1.PrintTable();
	system("PAUSE");
	return 0;
 }