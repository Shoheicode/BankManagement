#pragma once
#ifndef HASHNODE_H
#define HASHNODE_H

#include <iostream>
using namespace std;

class HashNode {
public:
	HashNode();
	HashNode(int, int);

	HashNode* next;
	int accountNumber;
	int password;
	
};

#endif // !HASHTABLE_H
