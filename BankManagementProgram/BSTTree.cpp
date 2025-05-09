#include "BSTTree.h"
#include <iostream>
#include <string>

BSTTree::BSTTree() {
	root = new BSTNode();
	
}

BSTTree::~BSTTree() {
	deleteAllNodes(root);

}

void BSTTree::deleteAllNodes(BSTNode* current) {
	if (current->left != nullptr) {
		deleteAllNodes(current->left);
	}
	if (current->right != nullptr) {
		deleteAllNodes(current->right);
	}

	delete current;
}

void BSTTree::addAccount(string name, string address, int accountNum, int password, int balance) {
	hash.addToHash(accountNum, password);
	ofstream writer;

	writer.open("server.txt", ios::app);
	writer << name << endl << address << endl << accountNum << endl << password << endl << balance << endl;
	writer.close();
	BSTNode* temp = new BSTNode(name, address, accountNum, password, balance);

	BSTNode* current = root;
	if (root == nullptr) {
		root = temp;
	}
	else {
		while (true) {
			if (accountNum < current->accountNum) {
				if (current->left == nullptr) {
					current->left = temp;
					break;
				}
				current = current->left;
			}
			else if (accountNum > current->accountNum) {
				if (current->right == nullptr) {
					current->right = temp;
					break;
				}
				current = current->right;
			}
		}
	}
}

void BSTTree::deleteAccount(int accountNum) {
	BSTNode* temp = root;
	if (temp == nullptr) {
		cout << "No Accounts" << endl;
	}
	else if (accountNum < temp->accountNum) {
		deleteAccountAll(temp->left, accountNum);
	}
	else if (accountNum > temp->accountNum) {
		deleteAccountAll(temp->right, accountNum);
	}
	else {
		BSTNode* temp2 = temp;
		if (temp->left && temp->right) {
			//BSTNode* temp2 = temp;
			temp2 = temp->right;
			temp2->left = temp->left;
			temp = nullptr;
			delete temp;
		}
		else {
			if (temp->left == nullptr) {
				temp2 = temp->right;
			}
			else if (temp->right == nullptr) {
				temp2 = temp->left;
			}
			delete temp;
		}
		delete root;
		root = temp2;
	}
}

void BSTTree::printInfo(BSTNode*) {
	if (root) {
		printInfo(root->left);
		cout << root->name << endl;
		cout << root->address << endl;
		cout << root->accountNum << endl;
		cout << root->password << endl;
		cout << root->balance << endl;
		printInfo(root->right);

	}
}

void BSTTree::deleteAccountAll(BSTNode* node, int accountNum) {
	if (node == nullptr) {
		return; // cout << "No Accounts" << endl;
	}
	else if (accountNum < node->accountNum) {
		deleteAccountAll(node->left, accountNum);
	}
	else if (accountNum > node->accountNum) {
		deleteAccountAll(node->right, accountNum);
	}
	else {
		BSTNode* temp2 = node;
		if (node->left && node->right) {
			//BSTNode* temp2 = temp;
			temp2 = node->right;
			temp2->left = node->left;
			node = nullptr;
			delete node;
		}
		else {
			if (node->left == nullptr) {
				temp2 = node->right;
			}
			else if (node->right == nullptr) {
				temp2 = node->left;
			}
			delete node;
		}
	}
}

void BSTTree::deposit(int acNum, int amt) {
	loadServer();
	BSTNode* temp = search(root, acNum);
	temp->balance = temp->balance + amt;

	vector <int> data;
	ifstream read;
	read.open("transaction.txt", ios::app);
	int line = 0;
	while (!read.eof())
	{
		read >> line;
		if (line == acNum)
		{
			data.push_back(line);
			line = amt;
			data.push_back(line);
			continue;
		}
		data.push_back(line);
	}
	read.close();
	ofstream write;
	write.open("temp.txt", ios::app);
	for (int i = 0; i < data.size(); i++)
	{
		write << data[i] << endl;
	}
	write.close();
	remove("transaction.txt");
	rename("temp.txt", "transaction.txt");

	updateServer(root);
}

void BSTTree::transfer(int sender_accountno, int reciever_accountno, int sender_amount)
{

}

void BSTTree::withdraw(int acNum, int amt) {
	loadServer();

	BSTNode* temp = new BSTNode(); //= search(root, acNum);
	temp->balance = temp->balance - amt;
	vector<int> data;

	ifstream read;
	read.open("transaction.txt", ios::app);
	int line = 0;
	while (!read.eof()) {
		read >> line;
		if (line == acNum) {
			data.push_back(line);
			line = amt * -1;
			data.push_back(line);
			continue;
		}
		data.push_back(line);
	}
	read.close();

	ofstream write;
	write.open("temp.txt", ios::app);
	for (int i = 0; i < data.size(); i++)
	{
		write << data[i] << endl;
	}
	write.close();
	remove("transaction.txt");
	rename("temp.txt", "transaction.txt");

	updateServer(root);

}

void BSTTree::loadServer(){
	ifstream read;
	read.open("server.txt", ios::app);

	string name = "";
	string adress = "";
	int accountno = 0;
	int password = 0;
	int balance = 0;
	//cin.ignore();
	while (!read.eof())
	{
		
		getline(read, name);
		getline(read, adress);
		read >> accountno;
		read >> password;
		read >> balance;
		read.ignore();
		read.ignore();

		cout << name << endl;
	}

	read.close();
}

void BSTTree::updateServer(BSTNode* root) {
	static int i = 0;
	if (i == 0)
	{
		i++;
		remove("server.txt");
	}
	ofstream write;
	write.open("server.txt");
	if (root)
	{
		updateServer(root->left);
		write << root->name << endl;
		write << root->address << endl;
		write << root->accountNum << endl;
		write << root->password << endl;
		write << root->balance << endl;
		updateServer(root->right);
	}
	write.close();

}

void BSTTree::findMax(BSTNode* root) {
	if (root) {
		findMax(root->left);
		v.push_back(root->accountNum);
		findMax(root->right);
	}
}

BSTTree::BSTNode* BSTTree::search(BSTNode* node, int accNum) {
	return nullptr;
}