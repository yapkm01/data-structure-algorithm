#include <iostream>
#include "linked_binary_tree.h"
using namespace std;

int LinkedBinaryTree::size() const {
	return n;
}

bool LinkedBinaryTree::empty() const {
	return size() == 0;
}

LinkedBinaryTree::Position LinkedBinaryTree::root() const {
	return Position(_root);
}

void LinkedBinaryTree::addRoot(Elm elm) {
	_root = new Node;
	_root->elm = elm;
	n = 1;
}

void LinkedBinaryTree::expandExternal(const Position& p, Elm elm1, Elm elm2) {
	Node* v = p.v;
	v->left = new Node;
	v->left->par = v;
	v->left->elm = elm1;
	v->right = new Node;
	v->right->par = v;
	v->right->elm = elm2;
	n =+2;
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
