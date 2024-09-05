#include "HashTable.h"
#include "HashNode.h"
#include "KeyNode.h"

HashTable::HashTable() {
	size = 12;
	hashTable = new KeyNode[12];
	cout << hashTable[0].data << endl;
};

HashTable::~HashTable() {
	delete hashTable;
	cout << "I AM DESTRUCTING" << endl;
	//delete hashTable;
};

void HashTable::startHash() {
	for (int i = 0; i < 12; i++) {
		KeyNode* temp = new KeyNode(i);
		hashTable[i] = *temp;

		loadHashTable();
	}
};

void HashTable::loadHashTable() {
	int acc = 0, r, pass;

	ifstream read;

	read.open("hashtable.txt");
	while (!read.eof()) {
		read >> acc;
		read >> pass;

		if (match(acc, pass)) {
			continue;
		}
		if (acc != -858993460 && pass - 858993460) {
			r = acc % 12;

			KeyNode* c = &hashTable[r];

			HashNode* node = new HashNode(acc, pass);
			if (c->nodes == nullptr) {
				c->nodes = node;
			}
			else {
				HashNode* root;
				root = c->nodes;

				while (root->next != nullptr) {
					root = root->next;
				}
				root->next = node;
			}
		}
		else {
			cout << "NO PASSWORD OR ACCOUNT PRESENTED" << endl;
		}


	}

	read.close();

};

void HashTable::addToHash(int acc, int pass) {
	static int i = 0;
	ofstream write;
	write.open("hashtable.txt", ios::app);
	if (i != 0) {
		write << endl;
		write << acc << endl << pass;
	}
	else {
		i++;
		write << acc << endl << pass;
	}
	write.close();

	startHash();

};

bool HashTable::match(int a, int p) {
	bool same = false;

	int r = a % 12;

	KeyNode* c = &hashTable[r];

	HashNode* c1 = c->nodes;

	while (c1 != nullptr) {
		if (c1->accountNumber == a && c1->password == p) {
			same = true;
			break;
		}
		c1->next;
	}

	return same;
};
