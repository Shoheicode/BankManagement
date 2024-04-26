#include "KeyNode.h"
#include "HashNode.h"

KeyNode::KeyNode() {
	next = nullptr;
	nodes = nullptr;
	data = 0;
}
KeyNode::KeyNode(int d) {
	data = d;
	next = nullptr;
	nodes = nullptr;
}