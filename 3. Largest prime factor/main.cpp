//https://projecteuler.net/problem=3

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> primeFactorization(long long n) {
	std::vector<long long> primeNumbers;
	long long i = 2;
	while(n != 1) {
		if(n % i == 0) {
			primeNumbers.push_back(i);
			n = n / i;
		} else {
			++i;
		}
	}
	return primeNumbers;
}

int main() {
	std::vector<long long> primeNumbers;
	long long n = 600851475143;
	primeNumbers = primeFactorization(n);

	std::cout << *std::max_element(primeNumbers.begin(), primeNumbers.end());
	return 0;
}
