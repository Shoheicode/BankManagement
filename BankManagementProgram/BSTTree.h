#pragma once
#ifndef BSTTREE_H
#define BSTTREE_H
#include "HashTable.h"
using namespace std;

class BSTTree {
public:
	BSTTree();
	~BSTTree();
	vector<int> v;
	HashTable hi;
	void addAccount(string, string, int, int, int);
	void deleteAccount(int);
	void withdraw(int, int);
	void deposit(int, int);
	void editAccountAdmin();
	void transfer(int, int, int);
	void transactionHistory();
	
private:
	struct BSTNode {
	public:
		//Nodes to the left and right in binary tree
		BSTNode* left;
		BSTNode* right;

		//Data members
		string name;
		string address;
		int accountNum;
		int password;
		int balance;

		BSTNode() {
			name = "";
			address = "";
			accountNum = 0;
			password = 0;
			balance = 0;
			left = nullptr;
			right = nullptr;
		};

		BSTNode(string n, string a, int acc, int pass, int bal) {
			name = n;
			address = a;
			accountNum = acc;
			password = pass;
			balance = bal;
			left = nullptr;
			right = nullptr;
		};
	};

	BSTNode* root;

	void deleteAllNodes(BSTNode* current);
	void copyNode(BSTNode* current, BSTNode* temp);
	
	void deleteAccountAll(BSTNode*, int);
	void findMax(BSTNode*);
	void loadServer();
	void updateServer(BSTNode*);
	BSTNode* search(BSTNode*, int acNum);
	void printInfo(BSTNode*);

};
#endif // !BSTTREE_H
