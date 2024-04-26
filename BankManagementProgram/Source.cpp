#include "BSTTree.h"
#include "Admin.h"
#include "fstream"
#include <windows.h>
#include "HashTable.h";

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

int main() {
	HashTable table;
	table.loadHashTable();

	string password = "";
	string username = "";
	int check = 0;
	while (check != 4){
		cout << "Login in as: " << endl;
		cout << "1-Admin" << endl;
		cout << "2-Staff" << endl;
		cout << "3-Customer" << endl;
		
		cin >> check;

		if (check == 1) {
			cout << "What is your username: ";
			cin >> username;
			cout << "What is the password: ";
			cin >> password;
			ifstream reader;
			reader.open("Admin.txt");
			string test;
			string pass;
			reader >> test;
			cout << test << endl;
			reader >> pass;
			cout << pass << endl;
			if (test == username && pass == password) {
				Admin a;				
			}
			cout << endl;

			cout << "Sorry, did not work. Sending you back to beginning" << endl;
			Sleep(2000);
			system("CLS");
			reader.close();
		}
		else if (check == 2) {
			system("CLS");
		}
		else if (check == 3) {
			system("CLS");
		}
	}
	system("pause");
	return 0;
}