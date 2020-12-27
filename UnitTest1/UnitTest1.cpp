#include "pch.h"
#include "CppUnitTest.h"
#include "../templates/vector.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define AUFGABE1
#define AUFGABE2
#define AUFGABE3
//#define AUFGABE4
//#define AUFGABE4_1

namespace UnitTest1 {
	TEST_CLASS(Expression) {
public:
#ifdef AUFGABE1
	// Aufgabe 1
	TEST_METHOD(VectorVector) {
		Vector<double, 5> A({ 1, 2, 3, 4, 5 });
		Vector<double, 5> B({ 1, 4, 9, 16, 25 });
		Vector<double, 5> C({ 2, 6, 12, 20, 30 });
		Vector<double, 5> D;

		D = A;
		Assert::IsTrue(D == A);
		D = A * A;
		Assert::IsTrue(D == B);
		Assert::IsTrue(A * A == B);
		Assert::IsTrue(B[4] == (A * A)[4]);

		auto E = B / A;
		Assert::IsTrue(E == A);
		Assert::IsTrue(A[3] == (B / A)[3]);
		Assert::IsTrue(A[3] == E[3]);

		Assert::IsTrue(C == A + B);
		Assert::IsTrue(C[2] == (B + A)[2]);

		Assert::IsTrue(C - A == B);
		Assert::IsTrue(A[1] == (C - B)[1]);

	}

	// Aufgabe 1
	TEST_METHOD(Expr) {
		Vector<double, 5> A({ 1, 2, 3, 4, 5 });
		Vector<double, 5> B({ 1, 4, 9, 16, 25 });
		Vector<double, 5> C({ 2, 6, 12, 20, 30 });

		auto D = A * B * C;
		Assert::IsTrue(D == C * B * A);
		Assert::IsTrue(D == B * C * A);
		Assert::IsTrue(D == B * A * C);

		auto E = B * C / A;
		Assert::IsTrue(E == B / A * C);
		Assert::IsTrue(C * B / A == E);

		Assert::IsTrue((A + B) * A == C * A);
		Assert::IsTrue(A * C == A * (B + A));
		Assert::IsTrue(A * (A + B) / A == C);
		Assert::IsTrue((C + B) / A == C / A + B / A);

		Assert::IsTrue((A + B) - B == A);
		Assert::IsTrue(A == (A - B) + B);
		Assert::IsTrue((A + B) - (C - A) == A);
		Assert::IsTrue(A + B + B + A == C + C - B + B - (A + A) + A + A);

		Assert::IsTrue((A * B)[1] == (C / A)[4] + (C / A)[0]);

	}
#endif
	/*
#ifdef AUFGABE2
	// Aufgabe 2
	TEST_METHOD(VectorScalar) {
		Vector<double, 5> A({ 1, 2, 3, 4, 5 });
		Vector<double, 5> B({ 0.5, 1.0, 1.5, 2.0, 2.5 });
		Vector<double, 5> C({ 2, 3, 4, 5, 6 });
		Vector<double, 5> D({ 3, 3, 3, 3, 3 });
		Vector<double, 5> E({ 3, 1, -1, -3, -5 });
		Vector<double, 5> F({ 2, 2, 2, 2, 2 });

		auto G = A * 0.5;
		auto H = 0.5 * A;
		Assert::IsTrue(G == B);
		Assert::IsTrue(H == B);
		Assert::IsTrue(B == G);
		Assert::IsTrue(B == H);

		Assert::IsTrue(A / 2.0 == B);
		Assert::IsTrue((2.0 / A)[3] == B[0]);
		Assert::IsTrue(B == A / 2.0);
		Assert::IsTrue(B[1] == (2.0 / A)[1]);

		Assert::IsTrue(A + 1.0 == C);
		Assert::IsTrue(1.0 + A == C);
		Assert::IsTrue(C == A + 1.0);
		Assert::IsTrue(C == 1.0 + A);

		Assert::IsTrue(C - 1.0 == A);
		Assert::IsTrue((5.0 - A)[1] == C[1]);
		Assert::IsTrue(A == C - 1.0);
		Assert::IsTrue(C[0] == (5.0 - A)[2]);

		auto e = (A + C + E) / 3.0;
		Assert::IsTrue(e == F);
		auto f = A + D;
		A = f;
		Assert::IsTrue(e == D);

		A[1] = 0;
		Assert::IsFalse(e == D);
	}
	
	// Aufgabe 2
	TEST_METHOD(ExprScalar) {
		Vector<double, 5> A({ 1, 2, 3, 4, 5 });
		Vector<double, 5> B({ 1, 4, 9, 16, 25 });
		Vector<double, 5> C({ 2, 6, 12, 20, 30 });
		Vector<double, 5> D({ 1, 1, 1, 1, 1 });

		Assert::IsTrue(A + B + B + A == 2.0 * C);
		Assert::IsTrue(C * 2.0 == (B + B) + (A + A));
		Assert::IsTrue(3.0 * (A + B) - (B + A) * 2.0 == C);

		Assert::IsTrue(3.0 + (A + B) - 3.0 == C);
		Assert::IsTrue(2.0 * (C - B) / 2.0 + B == (A * 4.0 + 4.0 * B) / 4.0);

		Assert::IsTrue((A + B) / C == D);
		Assert::IsTrue((((A + B) / C) * 9.0)[3] == B[2]);
		Assert::IsTrue(B[4] == (25.0 * ((C + B) / A) / 11.0)[4]);
	}
#endif
	
#ifdef AUFGABE3
	// Aufgabe 3
	TEST_METHOD(Sum) {
		Vector<double, 5> A({ 1, 2, 3, 4, 5 });

		Assert::IsTrue(15 == sum(A));
		Assert::IsTrue(30 == sum(2.0 * A));
		Assert::IsTrue(30 == sum(A * 2.0));
		Assert::IsTrue(55 == sum(A * A));

		Assert::IsTrue(14 == sum(A, 1));
		Assert::IsTrue(28 == sum(2.0 * A, 1));
		Assert::IsTrue(28 == sum(A * 2.0, 1));
		Assert::IsTrue(54 == sum(A * A, 1));

		Assert::IsTrue(5 == sum(A, 1, 3));
		Assert::IsTrue(10 == sum(2.0 * A, 1, 3));
		Assert::IsTrue(10 == sum(A * 2.0, 1, 3));
		Assert::IsTrue(13 == sum(A * A, 1, 3));
	}
#endif

#ifdef AUFGABE4
	// Aufgabe 4
	TEST_METHOD(DotProduct) {
		Vector<double, 5> A({ 1, 2, 3, 4, 5 });
		Vector<double, 5> B({ 1, 4, 9, 16, 25 });
		Vector<double, 5> C({ 2, 6, 12, 20, 30 });
		auto D = A * *B;

		Assert::IsTrue(D == B * *A);
		Assert::IsTrue(double(D) == 1.0 + 8 + 27 + 64 + 125);
		double d = A * *(A + B);
		Assert::IsTrue(d == (B + A) * *A);
		d = (B + A) * *A;
		Assert::IsTrue(A * *(A + B) == d);
		Assert::IsTrue(D * (A + B) / (B * *A) == C);
		Assert::IsTrue(D * C - B * (B * *A) == A * (A * *B));
		Assert::IsTrue((A * A) * *(B * B) == (A * B) * *(B * A));
		Assert::IsTrue(A * *B * 2.0 == 2.0 * B * *A);
		d = A * *B * 2.0;
		Assert::IsTrue(d == 2.0 * B * *A);
		d = 2.0 * B * *A;
		Assert::IsTrue(2.0 * B * *A == d);
		d = 2.0 + A * *B - 2.0;
		Assert::IsTrue(d == B * *A);
	}
#endif
#ifdef AUFGABE4_1
	TEST_METHOD(DotProduct2) {
		Vector<double, 5> A({ 1, 2, 3, 4, 5 });
		Vector<double, 5> B({ 1, 4, 9, 16, 25 });

		Assert::IsTrue(50625 == A * *(B * (A * *B)));
		Assert::IsTrue(50625 == (A * *B) * (A * *B));
	}
#endif*/
	};
}