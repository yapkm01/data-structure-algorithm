#include "euler_tour.h"

int EulerTour::templateEulerTour(const Position& p) const {

	Result r = initResult();

	if (p.isExternal())
		visitExternal(p, r);
	else {
		visitLeft(p, r);
		r.leftResult = templateEulerTour(p.left());
		visitBelow(p, r);
		r.rightResult = templateEulerTour(p.right());
		visitRight(p, r);
	}
	return result(r);

}
