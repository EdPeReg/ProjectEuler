// https://projecteuler.net/problem=7

/* Remember this:
 * Todo numero primo es impar pero no todo impar es primo. 
 * I can apply that, incrementing i by 2 and starting from 3. */

#include <iostream>
#include <vector>
#include <cmath>


bool isPrime(long long n) {
	long long i = 2;
	long long squareNumber = sqrt(n); // Square root to get a better performance. 
	while(n > 1 and i <= squareNumber) {
		if(n % i == 0) {
			return false;
		} else {
			++i;
		}
	}
	return true;
}

std::vector<long long> generatePrimes(long long k) {
	std::vector<long long> primes;

	long long i = 2;
	while(k) {
		if(isPrime(i)) {
			primes.push_back(i);
			--k;
		} 
		i++;
	}

	return primes;
}

int main() {
	long n;
	std::cin >> n;
	std::vector<long long> primes = generatePrimes(n);
	
	std::cout << "Primes list: ";
	for(const long long &p : primes) {
		std::cout << p << " ";
	}

	std::cout << "\nLast prime: " << primes.at(primes.size() - 1) << '\n';

	return 0;
}
