#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class KeyNode;
class HashTable {
public:
	HashTable();
	~HashTable();
	void startHash();
	void loadHashTable();
	void addToHash(int, int);
	bool match(int, int);
	void display();
	void displayPasswords();
	void deletePassword(int);

private:
	KeyNode* hashTable;
	int size;
};

#endif // !HASHTABLE_H
