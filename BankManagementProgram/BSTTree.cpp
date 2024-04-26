#include "BSTTree.h"

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
	hi.addToHash(accountNum, password);
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
	
}

void BSTTree::deleteAccountAll(BSTNode* node, int accountNum) {

}