//https://projecteuler.net/problem=6

/* Insted using brute force, we can use their formulas.
 * Sum: n(n+1)/2 
 * Sum of square: n(n+1)(2n+1)/6
 * */


#include <iostream>
#include <cmath>
#include <sstream>

int main() {
	size_t n = 1000000000;
	size_t sum = (n*(n + 1))/2;
	size_t sumSquare = (n*(n + 1) * (2*n + 1))/6;

	std::cout << pow(sum, 2) - sumSquare << '\n';

	// Convert to decimal.
	std::ostringstream ss;
	ss << std::fixed << pow(sum, 2) - sumSquare;
	std::cout << ss.str();

	return 0;
}
