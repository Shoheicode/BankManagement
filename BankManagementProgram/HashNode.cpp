#include "HashNode.h"

HashNode::HashNode() {
	next = nullptr;
	accountNumber = 0;
	password = 0;
}

HashNode::HashNode(int acc, int pass) {
	next = nullptr;
	accountNumber = acc;
	password = pass;
}