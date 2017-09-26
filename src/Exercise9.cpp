//=============================================================================
// Name        : Exercise9.cpp
// Author      : Anders Reiche
// Version     :
// Copyright   : Open Source
// Description :
//=============================================================================

#include <iostream>
#include <assert.h>
using namespace std;

int factorial(int n);

// summing function
template<class T>
T sum_n(T x, int n) {
	T a = 0;;
	T b = 0;


	// calculate x^n
	if (n > 0) {
		a = 1;	// if a = 0 everything returns 0;
		for (int i = 0; i <= n; i++) {
			a *= x;
		}
	}

	// calculate n!
	b = factorial(n);

	return a / b;
}

// exp(x) = sum_n (x^n/n!)
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
	cout << expfak(1) << '\n';
	cout << expfak(2) << '\n';
	cout << expfak(3) << '\n';
	cout << expfak(4) << '\n';
	cout << expfak(5) << '\n';
	assert(expfak(0) == 0);
	assert(expfak(1) == 2);
	assert(expfak(3) == 5);
	assert(expfak(4) == 8);
	assert(expfak(5) == 11);

	return 0;
}

// factorial function
int factorial(int n) {
	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;
}
