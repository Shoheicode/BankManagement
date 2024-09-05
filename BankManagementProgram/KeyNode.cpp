#include "KeyNode.h"
#include "HashNode.h"

KeyNode::KeyNode() {
	cout << "I AM BEING CREATED" << endl;
	next = nullptr;
	nodes = nullptr;
	data = 0;
}
KeyNode::KeyNode(int d) {
	data = d;
	next = nullptr;
	nodes = nullptr;
}
KeyNode::~KeyNode() {
	cout << "I AM LEAVING BYEE" << endl;
	delete next;
	delete nodes;
}