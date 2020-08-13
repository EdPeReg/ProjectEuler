//https://projecteuler.net/problem=6

#include <iostream>
#include <cmath>
#include <sstream>

int main() {
	long long sum = 0, sum2 = 0;

	// Just use brute force, but with bigger number is bad.
	for(long long i = 1; i <= 100; ++i) {
		sum2 += i;
		sum += pow(i, 2);
	}

	std::cout << pow(sum2, 2) - sum << '\n';

	// Convert to decimal.
	std::ostringstream ss;
	ss << std::fixed << pow(sum2, 2) - sum;
	std::cout << ss.str();

	return 0;
}
