
#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H

#include <list>

typedef int Elm; 

class LinkedBinaryTree {

	public:
		LinkedBinaryTree();

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
		};

		typedef std::list<Position>  PositionList;

		int size() const;
		bool empty() const;
		Position root() const;
		PositionList positions() const;
		void addRoot(int elm);
		void createRecord(Position& p, int elm);
		void insertRecord(const Position& p, Node* new_n) const;

	protected:
		void preorder(Node* v, PositionList& pl) const;
		void postorder(Node* v, PositionList& pl) const;
		void inorder(Node* v, PositionList& pl) const;

	private:
		Node*  _root;
		int n;

};

#endif

