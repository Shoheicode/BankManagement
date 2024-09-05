#pragma once
#include "BSTTree.h"
#include "Hashtable.h"

void customer() {
	BSTTree t;
	HashTable h;

	int condition = 0;
	while (condition != 3) {
		cout << "Welcome Customer" << endl;
		cout << "choose the following please" << endl;
		cout << "press 1 to see account details" << endl;
		cout << "press 2 to see transaction history  " << endl;
		cout << "press 3 to exit" << endl;
		cin >> condition;
		if (condition == 1) {
			int accountno;
			cout << "please enter account number" << endl;
			cin >> accountno;
			BSTTree::BSTNode* temp = t.search(t.getRoot(), accountno);
			if (temp == nullptr){
				
			}
			else {
				cout << "Account Details Are :\t\t\t\t\t\t " << endl << endl;
				cout << "NAME :" << temp->name << endl;
				cout << "ADRESS :" << temp->address << endl;
				cout << "ACCOUNT NUMBER :" << temp->accountNum << endl;
				cout << "PASSWORD :" << temp->password << endl;
				cout << "BALANCE :" << temp->balance << endl;
			}
		}
		else if (condition == 2) {

		}
		else if (condition == 3) {
			condition = 3;
		}
		else {
			cout << "Please insert a valid response" << endl;
			condition = 0;
			system("CLS");
		}
	}
}