#include<iostream>
#include<string>
#include"hash.h"

hash::hash() {
	for (int i = 0; i < tableSize; i++) {
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = nullptr;
	}
}

void hash::AddItem(std::string name, std::string drink) {
	int index = Hash(name);
	if(HashTable[index]->name=="empty"){
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else {
		item* Ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;
		while (Ptr->next != NULL) {
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

int hash::NumberOfItemsInIndex(int index) {
	int count = 0;
	if (HashTable[index]->name=="empty") {
		return count;
	}
	else {
		count++;
		item* Ptr = HashTable[index];
		while (Ptr->next != NULL) {
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

void hash::PrintTable() {
	int number;
	for (int i = 0; i < tableSize;i++) {
		number = NumberOfItemsInIndex(i);
		std::cout << "index = "<<i<<std::endl;
		std::cout <<HashTable[i]->name <<std::endl;
		std::cout << HashTable[i]->drink << std::endl;
		std::cout << "number of items = " << number<< std::endl;
		std::cout << "---------------------" << std::endl;
	}
}
int hash::Hash(std::string key) {
	int hash = 0;
	int index;
	for (int i = 0; i < key.length();i++) {
		hash = hash + (int)key[i];
	}
	index = hash % tableSize;
	return index;
}
void hash:: PrintItemsOfIndex(int index) {
	item* Ptr = HashTable[index];
	if (Ptr->name == "empty") {
		std::cout << "index " << index << " is empty.";
	}
	else {
		std::cout << "index " << index << " contains the following items:\n";
		while (Ptr != nullptr) {
			std::cout << Ptr->name << std::endl;
			std::cout << Ptr->drink << std::endl;
			Ptr = Ptr->next;
		}
	}
}void hash::FindDrink(std::string name) {
	int index = Hash(name);
	item* Ptr = HashTable[index];
	while (Ptr!=nullptr) {
		if (Ptr->name == name) {
			std::cout << name << "'s " << "drink is " << Ptr->drink << std::endl;
			break;
		}
		Ptr = Ptr->next;
	}
	if (Ptr == nullptr) {
		std::cout << name << " is not in the Hash Table.\n";
	}
}
void hash::RemoveItem(std::string name) {
	item* delPtr;
	item* P1;
	item* P2;
	int index = Hash(name);
	if (HashTable[index]->name == "empty") {
		std::cout << name << " is not in Hash Table.\n";
	}
	else if(HashTable[index]->name==name && HashTable[index]->next==nullptr) {
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
	}
	else if (HashTable[index]->name == name) {
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;
		std::cout << name << " is removed from Hash Table.\n";
	}
	else {
		P1 = HashTable[index]->next;
		P2 = HashTable[index];
		while (P1 != nullptr && P1->name != name) {
			P2 = P1;
			P1 = P1->next;
		}
		if(P1==nullptr){
			std::cout << name << " is not in Hash Table.\n";
		}
		else {
			delPtr = P1;
			P2->next = P1->next;
			delete delPtr;
		}
	}

}



