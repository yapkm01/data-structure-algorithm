
#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H

#include <iostream>
#include <sstream>
#include <list>
#include <functional>

typedef char Elm; 

class LinkedBinaryTree {

	public:
		LinkedBinaryTree(): _root(nullptr), n(0) {}

	protected:

		struct Node {
			Elm elm;
			Node* par;
			Node* left;
			Node* right;
			Node(): elm(), par(nullptr), left(nullptr), right(nullptr) {}
		};

	public:

		class Position {
			friend class LinkedBinaryTree;
			private:
				Node* v;
			public:
				Position(Node* _v = nullptr): v(_v) {}
				Elm& operator*() const {
					return v->elm;
				}
				Position left() const {
					return Position(v->left);
				}
				Position right() const {
					return Position(v->right);
				}
				Position parent() const {
					return Position(v->par);
				}
				bool isRoot() const {
					return v->par == nullptr;
				}
				bool isExternal() const {
					return v->left == nullptr && v->right == nullptr;
				}
				Elm& value() const {
					return v->elm;
				}
				void print() const {
					std::cout << v->elm;
				}
				int operation(int leftResult, int rightResult) const {
					std::function<int(int, int)> op;
					char opr = v->elm;
					if (opr == '+')
						op = std::plus<int>();
					else if (opr == '-') 
						op = std::minus<int>();
					else if (opr == '*') 
						op = std::multiplies<int>();
					else if (opr == '/') 
						op = std::divides<int>();
					return op(leftResult, rightResult);
				}
		};

		typedef std::list<Position> PositionList;

		int size() const;
		bool empty() const;
		Position root() const;
		void addRoot(Elm elm);
		void expandExternal(const Position& p, Elm elm1, Elm elm2);
		PositionList positions(int trv) const;

	protected:
		void preorder(Node* v, PositionList& pl) const;
		void postorder(Node* v, PositionList& pl) const;
		void inorder(Node* v, PositionList& pl) const;

	private:
		Node*  _root;
		int n;

};

#endif

