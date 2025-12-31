
#ifndef COMPARATOR_H
#define COMPARATOR_H

template <typename T>
class Comparator {
	public:
		bool operator()(T p, T q) const {
			return p < q;
		}
};

#endif
