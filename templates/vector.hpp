#pragma once
#include <array>
#include <iostream>
#include "Expression.hpp"
#include "Ops.hpp"

template <typename T, int S>
class Vector : public std::array<T, S> {

protected:

public:
	Vector(const std::initializer_list<T>& data) {
		size_t s = __min(data.size(), S);

		auto it = data.begin();

		for (size_t i = 0; i < s; i++) this->at(i) = *it++;
	}

	Vector operator+(Vector& r) {
		Expression<Vector, Add, Vector> e = Expression<Vector, Add, Vector>(*this, r);
		return e.apply();
	}

	Vector operator-(Vector& r) {
		Expression<Vector, Sub, Vector> e = Expression<Vector, Sub, Vector>(*this, r);
		return e.apply();
	}

	void print() {
		for (int i = 0; i < this->size(); i++) {
			std::cout << (*this)[i] << ' ';
	}
	
	}

};
