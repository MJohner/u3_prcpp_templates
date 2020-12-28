#pragma once
#include <array>
#include <iostream>
#include "Expression.hpp"
#include "Ops.hpp"
#include <iostream>

template <typename T, size_t S>
class Vector : public std::array<T, S> {

public:

	Vector() {};

	Vector(const std::initializer_list<T>& data) {
		size_t s = __min(data.size(), S);
		auto it = data.begin();
		for (size_t i = 0; i < s; i++) this->at(i) = *it++;
	}

	template<typename Left, typename Op, typename Right>
	Vector& operator=(const Expression<Left, Op, Right>& e) {
		if (this->size() == e.size()) {
			for (size_t i = 0; i < e.size(); i++) {
				(*this)[i] = e[i];
			}
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		os << "[";
		for (size_t i = 0; i < v.size()-1; i++) {
			os << v[i] << ", ";
		}
		os << v[v.size() - 1] << "]" ;
		return os;
	}

	void print() {
		for (int i = 0; i < this->size(); i++) {
			std::cout << (*this)[i] << ' ';
	}
	
	}
	bool operator==(const Vector other) const {
		if (this->size() != other.size()) {
			return false;
		}
		for (size_t i = 0; i < other.size(); i++) {
			if ((*this)[i] != other[i]) {
				return false;
			}
		}
		return true;
	}
};

template<typename T, size_t S>
T sum(const Vector<T, S>& v, size_t from, size_t to) {
	T subsum = 0;
	for (; from < to; from++) {
		subsum += v[from];
	}
	return subsum;
}

template<typename T, size_t S>
T sum(const Vector<T, S>& v, size_t from = 0) {
	return sum(v, from, v.size());
}