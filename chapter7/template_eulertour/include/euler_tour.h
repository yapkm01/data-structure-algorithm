
#ifndef EULERTOUR_H
#define EULERTOUR_H

#include <iostream>
#include "linked_binary_tree.h"

typedef int Rslt;

class EulerTour {

	protected:
		typedef LinkedBinaryTree::Position Position;

		struct Result {
			Rslt leftResult;
			Rslt rightResult;
			Rslt finalResult;
		};

		const LinkedBinaryTree* tree;

	public:
		void initialize(const LinkedBinaryTree& T) {
			tree = &T;
		}

	protected:
		int templateEulerTour(const Position& p) const;
		virtual void visitExternal(const Position& p, Result& r) const {}
		virtual void visitLeft(const Position& p, Result& r) const {}
		virtual void visitBelow(const Position& p, Result& r) const {}
		virtual void visitRight(const Position& p, Result& r) const {}

		Result initResult() const {
			return Result();
		}
		int result(const Result& r) const {
			return r.finalResult;
		}

};

#endif

