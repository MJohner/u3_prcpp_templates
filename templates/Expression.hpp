#pragma once
#include "Ops.hpp"
#include <iostream>
#include <type_traits>
template<typename Left, typename Op, typename Right> class Expression {
	const Left& m_left;
	const Right& m_right;
public:
	using type = typename std::conditional<std::is_arithmetic_v<Left>,
		Left,
		Right>::type;

	Expression(const Left& l, const Right& r) : m_left{ l }, m_right{ r } {
	std::cout << typeid(type).name() << std::endl; }

	size_t size() const { return m_left.size(); }


	typename type operator[](size_t i) const{
		if constexpr (!std::is_arithmetic_v<Left> && !std::is_arithmetic_v<Right>) {
			return Op::template apply<type>(m_left[i], m_right[i]);
		}
		else if constexpr (std::is_arithmetic_v<Left> && !std::is_arithmetic_v<Right>) {
			return Op::template apply<type>(m_left, m_right[i]);
		}
		else if constexpr (!std::is_arithmetic_v<Left> && std::is_arithmetic_v<Right>) {
			return Op::template apply<type>(m_left[i], m_right);
		}	
	}

	friend std::ostream& operator<<(std::ostream& os, const Expression<Left, Op, Right>& e)
	{
		os << "[";
		for (size_t i = 0; i < e.size() - 1; i++) {
			os << e[i] << ", ";
		}
		os << e[e.size() - 1] << "]";
		return os;
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

template<typename Left, typename Right>
Expression<Left, Add, Right> operator+(const Left& l, const Right& r) {
	return Expression<Left, Add, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Sub, Right> operator-(const Left& l, const Right& r) {
	return Expression<Left, Sub, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Mul, Right> operator*(const Left& l, const Right& r) {
	return Expression<Left, Mul, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Div, Right> operator/(const Left& l, const Right& r) {
	return Expression<Left, Div, Right>(l, r);
}