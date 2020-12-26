#pragma once

template<typename Left, typename Op, typename Right> class Expression {
	const Left& m_left;
	const Right& m_right;
public: 
	using value_type = typename Left::value_type;

	Expression(const Left& l, const Right& r) : m_left{ l }, m_right{ r } {}

	size_t size() const { return m_left.size(); }

	Left apply() const{
		Left v = Left({});
		if (m_left.size() == m_right.size()) {
			
			for (size_t i = 0; i < m_left.size(); i++) {
				v[i] = (*this)[i];
			}
		}
		return v;
	}
	value_type operator[](size_t i) const{
		return Op::template apply<value_type>(m_left[i], m_right[i]);
	}
};