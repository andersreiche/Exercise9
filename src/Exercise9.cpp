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
T sum_n(T x, T n) {
	return pow(x, n / factorial(n));
}

//sums up the factorials and powers
template<class T>
T expfak(T x) {
	T result = 0;

	// loop the summing function x times
	for (T n = 0; n <= x; n++) {
		result += sum_n(x, n);
	}

	return result;
}

int main() {

	int num = 12;

	cout << endl << "x = integers 1-" << num << endl;
	for (int i = 0; i < num; i++) {
		cout << "expfak(" << i << ") = " << expfak<int>(i) << '\n';
	}

	cout << endl << "x = long long 1-" << num <<endl;
	for (long long i = 0; i < num; i++) {
		cout << "expfak(" << i << ") = " << expfak<long long>(i) << '\n';
	}

	cout << endl << "x = double 1-" << num << endl;
	for (double i = 0.0; i < num; i++) {
		cout << "expfak(" << i << ") = " << expfak<double>(i) << '\n';
	}

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

	assert(expfak<int>(0) == 1);
	assert(expfak<int>(1) == 2);
	assert(expfak<int>(2) == 5);
	assert(expfak<int>(3) == 8);
	assert(expfak<int>(4) == 11);
	assert(expfak<int>(5) == 14);

}
