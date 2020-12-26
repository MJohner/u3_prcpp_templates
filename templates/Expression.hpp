#pragma once
#include "Ops.hpp"
template<typename Left, typename Op, typename Right> class Expression {
	const Left& m_left;
	const Right& m_right;
public: 
	using value_type = typename Left::value_type;

	Expression(const Left& l, const Right& r) : m_left{ l }, m_right{ r } {}

	size_t size() const { return m_left.size(); }

	friend std::ostream& operator<<(std::ostream& os, const Expression& e)
	{
		os << "["; 
		
		for (int i = 0; i < e.size() - 1; i++) {
			os << e[i] << ", ";
		}
		os << e[e.size() - 1] << "]";
		return os;
	}
	value_type operator[](size_t i) const{
		return Op::template apply<value_type>(m_left[i], m_right[i]);
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