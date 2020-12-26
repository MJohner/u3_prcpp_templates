#pragma once
struct Add {
	template<typename T> static T apply(T l, T r) {
		return l + r;
	}
};

struct Sub {
	template<typename T> static T apply(T l, T r) {
		return l - r;
	}
};

struct Mul {
	template<typename T> static T apply(T l, T r) {
		return l * r;
	}
};

struct Div {
	template<typename T> static T apply(T l, T r) {
		return l / r;
	}
};