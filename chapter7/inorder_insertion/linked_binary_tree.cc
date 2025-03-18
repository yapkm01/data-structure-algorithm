#include <iostream>
#include <list>
#include "linked_binary_tree.h"
using namespace std;

LinkedBinaryTree::LinkedBinaryTree(): _root(nullptr), n(0) {}

int LinkedBinaryTree::size() const {
	return n;
}

bool LinkedBinaryTree::empty() const {
	return size() == 0;
}

LinkedBinaryTree::Position LinkedBinaryTree::root() const {
	return Position(_root);
}

void LinkedBinaryTree::addRoot(int elm) {
	_root = new Node;
	n = 1;
	_root->elm = elm;
}

void LinkedBinaryTree::createRecord(Position& p, int elm) {
	Node* new_p = new Node;
	new_p->elm = elm;
	++n;
	insertRecord(p, new_p);
}

void LinkedBinaryTree::insertRecord(const Position& p, Node* new_n) const {
	Node* v = p.v;
	if (v->left != nullptr && new_n->elm < v->elm)
		insertRecord(Position(v->left), new_n);
	else if (v->left == nullptr && new_n->elm < v->elm) {
		v->left = new_n;
		return;
	}
	if (v->right != nullptr && new_n->elm > v->elm)
		insertRecord(Position(v->right), new_n);
	else if (v->right == nullptr && new_n->elm > v->elm) {
		v->right = new_n;
		return;
	}
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const {
	PositionList pl;
	inorder(_root, pl);
	return PositionList(pl);
}

void LinkedBinaryTree::inorder(Node* v, PositionList& pl) const {
	if (v->left != nullptr)
		inorder(v->left,pl);
	pl.push_back(Position(v));
	if (v->right != nullptr)
		inorder(v->right,pl);
}
