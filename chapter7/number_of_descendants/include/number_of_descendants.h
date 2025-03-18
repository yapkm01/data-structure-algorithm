
#ifndef NUMBEROFDESCENDANTS_H
#define NUMBEROFDESCENDANTS_H

#include "linked_binary_tree.h"

typedef int Rslt;

class NumberOfDescendants {

	protected:
		struct Result {
			Rslt leftResult;
			Rslt rightResult;
		};

		typedef ::LinkedBinaryTree LinkedBinaryTree;
		typedef LinkedBinaryTree::Position Position;

	protected:
		const LinkedBinaryTree* tree = nullptr;

	public:
		void initialize(const LinkedBinaryTree& T) {
			tree = &T;
		}

		void execute(const LinkedBinaryTree& T) {
			int globalCnt = 0;
			initialize(T);
			eulerTour(T.root(), globalCnt);
		}

	protected:
		void eulerTour(const Position& p, int& globalCnt) const;
		void visitExternal(const Position& p, Result& r, int& globalCnt) const;
		void visitLeft(const Position& p, Result& r, int& globalCnt) const;
		void visitBelow(const Position& p, Result& r, int& globalCnt) const;
		void visitRight(const Position& p, Result& r, int& globalCnt) const;
		Result initResult() const {
			return Result();
		}

};

#endif

