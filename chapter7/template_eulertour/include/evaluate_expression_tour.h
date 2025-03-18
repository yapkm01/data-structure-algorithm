
#ifndef EVALUATEEXPRESSIONTOUR_H
#define EVALUATEEXPRESSIONTOUR_H

#include "euler_tour.h"

class EvaluateExpressionTour : public EulerTour {

	protected:
		typedef EulerTour::Position Position;
		typedef EulerTour::Result Result;

	public:
		void execute(const LinkedBinaryTree& T) {
			initialize(T);
			std::cout << "The value is: " << templateEulerTour(T.root()) << "\n";
		}

	protected:
		virtual void visitExternal(const Position& p, Result& r) const {
			std::stringstream strm;
			strm << p.value();
			r.finalResult = stoi(strm.str());
		}
		virtual void visitRight(const Position& p, Result& r) const {
			r.finalResult = p.operation(r.leftResult, r.rightResult); }

};

#endif

