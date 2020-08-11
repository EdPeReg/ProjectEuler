//https://projecteuler.net/problem=3
// Nice explanation about how the square root improves everything.
// http://mathcentral.uregina.ca/QQ/database/QQ.09.00/paul2.html

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<long long> primeFactorization(long long n) {
	std::vector<long long> primeFactors;
	long long i = 2;

	int squareNumber = sqrt(n);
	while(n > 1 and i <= squareNumber) {
		if(n % i == 0) {
			primeFactors.push_back(i);
			n = n / i;
			squareNumber = sqrt(n);
		} else {
			++i;
		}
	}

	primeFactors.push_back(n);
	return primeFactors;
}

int main() {
	std::vector<long long> primeFactors;
	long long n = 458759;
	primeFactors = primeFactorization(n);

	for(const long long& primeFactor : primeFactors) {
		std::cout << primeFactor << " ";
	}

	std::cout << "\nLargest prime factor: " << *std::max_element(primeFactors.begin(), primeFactors.end());
	return 0;
}
