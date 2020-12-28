#include "vector.hpp"

int main(int argc, char* argv[]) {
	Vector<double, 4> A({ 1, 2, 3, 4 });
	Vector<double, 4> B({ 2, 1, 0, 1 });
	Vector<double, 4> D;
	auto e = (A - B) * (A + B) ;
	D = e;
	std::cout << D << std::endl; // [-3,3,9,15]
	B = { 3, 0, 2, 5 };
	std::cout << e << std::endl; // [-8,4,5,-9]
	B = { 4, 3, 3, -2 };
	std::cout << e[1] << std::endl; // -5
	D = A + 3;
	std::cout << D << std::endl; // [-3,3,9,15]


}
