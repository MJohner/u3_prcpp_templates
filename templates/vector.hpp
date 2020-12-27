#pragma once
#include <array>
#include <iostream>
#include "Expression.hpp"
#include "Ops.hpp"
#include <iostream>

template <typename T, size_t S>
class Vector : public std::array<T, S> {


public:
	Vector(const std::initializer_list<T>& data) {
		size_t s = __min(data.size(), S);
		auto it = data.begin();
		for (size_t i = 0; i < s; i++) this->at(i) = *it++;
	}

	Vector() {};

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
	template<typename O>
	bool operator==(const O other) const {
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
