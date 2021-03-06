//https://projecteuler.net/problem=3

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> primeFactorization(long long n) {
	std::vector<long long> primeFactors;
	long long i = 2;

	while(n > 1) {
		if(n % i == 0) {
			primeFactors.push_back(i);
			n = n / i;
		} else {
			++i;
		}
	}

	return primeFactors;
}

int main() {
	std::vector<long long> primeFactors;
	long long n = 458759;
	primeFactors = primeFactorization(n);

	for(const long& primeFactor : primeFactors) {
		std::cout << primeFactor << " ";
	}

	std::cout << "\nLargest prime factor: " << *std::max_element(primeFactors.begin(), primeFactors.end());
	return 0;
}
