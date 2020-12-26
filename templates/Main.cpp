#include "vector.hpp"

int main(int argc, char* argv[]) {
	Vector<int, 10> v1 = Vector<int, 10>({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
	Vector<int, 10> v2 = Vector<int, 10>({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
	(v1 + v2).print();
}
