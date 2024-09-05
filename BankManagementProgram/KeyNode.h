#pragma once
#ifndef KEYNODE_H
#define KEYNODE_H

#include <iostream>
using namespace std;

class HashNode;
class KeyNode {
public:
	KeyNode();
	KeyNode(int);
	~KeyNode();

	int data;
	KeyNode* next;
	HashNode* nodes;

};

#endif 