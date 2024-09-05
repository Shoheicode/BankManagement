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

		}
		else if (condition == 2) {

		}
		else if (condition == 3) {
			condition = 3;
		}
		else {
			cout << "Please insert a valid response" << endl;
			condition = 0;
		}
	}
}