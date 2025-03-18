
#ifndef PRINTEXPRESSIONTOUR_H
#define PRINTEXPRESSIONTOUR_H

#include "euler_tour.h"

class PrintExpressionTour : public EulerTour {

	protected:
		typedef EulerTour::Position Position;
		typedef EulerTour::Result Result;

	public:
		void execute(const LinkedBinaryTree& T) {
			initialize(T);
			std::cout << "Expression: "; 
			templateEulerTour(T.root());
			std::cout << std::endl;
		}

	protected:
		virtual void visitExternal(const Position& p, Result& r) const {
			p.print(); 
		}
		virtual void visitLeft(const Position& p, Result& r) const {
			std::cout << "(";
		}
		virtual void visitBelow(const Position& p, Result& r) const {
			p.print();
		}
		virtual void visitRight(const Position& p, Result& r) const {
			std::cout << ")"; }

};

#endif

