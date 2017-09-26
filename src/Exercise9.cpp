//=============================================================================
// Name        : Exercise9.cpp
// Author      : Anders Reiche
// Version     :
// Copyright   : Open Source
// Description :
//=============================================================================

#include <iostream>
#include <assert.h>
#include <cmath>
using namespace std;

int factorial(int n);
void test(void);

// calculates factorial and power and divides them
template<class T>
T sum_n(T x, int n) {
	return pow(x, n) / factorial(n);
}

//
template<class T>
T expfak(T x) {
	T result = 0;

	// loop the summing function x times
	for (int n = 0; n <= x; n++) {
		result += sum_n(x, n);
	}

	return result;
}

int main() {
	cout << expfak<int>(1) << '\n';
	cout << expfak<int>(2) << '\n';
	cout << expfak<int>(3) << '\n';
	cout << expfak<int>(4) << '\n';
	cout << expfak<int>(5) << '\n';
	test();

	return 0;
}

// factorial function
int factorial(int n) {
	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;
}

// runs the algorithm against the target output results
void test(void) {
	assert(factorial(0) == 1);
	assert(factorial(1) == 1);
	assert(factorial(2) == 2);
	assert(factorial(3) == 6);
	assert(factorial(4) == 24);
	assert(factorial(5) == 120);

	assert(pow(2, 0) == 1);
	assert(pow(2, 1) == 2);
	assert(pow(2, 2) == 4);
	assert(pow(2, 3) == 8);
	assert(pow(2, 4) == 16);
	assert(pow(2, 5) == 32);

	assert(expfak<int>(0) == 0);
	assert(expfak<int>(1) == 2);
	assert(expfak<int>(3) == 5);
	assert(expfak<int>(4) == 8);
	assert(expfak<int>(5) == 11);

}
