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
