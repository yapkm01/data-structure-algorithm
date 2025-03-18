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

void LinkedBinaryTree::addRoot() {
	_root = new Node;
	n = 1;
	_root->elm = n;
}

void LinkedBinaryTree::expandExternal(const Position& p) {
	Node* v = p.v;
	v->left = new Node;
	v->left->par = v;
	v->left->elm = ++n;
	v->right = new Node;
	v->right->par = v;
	v->right->elm = ++n;
}

LinkedBinaryTree::Position LinkedBinaryTree::removeAboveExternal(const Position& p) {
	Node* w = p.v; 
	Node* v = w->par;
	Node* sib = (w == v->left ? v->right : v->left);
	if (v==_root) {
		_root = sib;
		sib->par = nullptr;
	} else {
		Node* gpar = v->par;
		if (v == gpar->left) gpar->left = sib;
		else gpar->right = sib;
		sib->par = gpar;
	}
	delete w; 
	delete v;
	n -= 2;
	return Position(sib);
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions(int trv) const {
	PositionList pl;
	if (trv == 1)
		preorder(_root, pl);
	else if (trv == 2)
		inorder(_root, pl);
	else postorder(_root, pl);
	return PositionList(pl);
}

void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {
	pl.push_back(Position(v));
	if (v->left != nullptr)
		preorder(v->left, pl);
	if (v->right != nullptr)
		preorder(v->right, pl);
}

void LinkedBinaryTree::postorder(Node* v, PositionList& pl) const {
	if (v->left != nullptr)
		postorder(v->left, pl);
	if (v->right != nullptr)
		postorder(v->right, pl);
	pl.push_back(Position(v));
}

void LinkedBinaryTree::inorder(Node* v, PositionList& pl) const {
	if (v->left != nullptr)
		inorder(v->left, pl);
	pl.push_back(Position(v));
	if (v->right != nullptr)
		inorder(v->right, pl);
}
