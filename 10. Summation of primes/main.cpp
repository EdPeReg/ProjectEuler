#include <iostream>
#include <vector>

// Sieve of Eratosthenes https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
std::vector<long> generatePrimes(long k) {
	std::vector<bool> visited(k - 1, true);
	std::vector<long> primes;

	for(long i = 2; i < k; ++i) {
		if(visited.at(i - 2) == true) {
			// If is not prime, then is false.
			for(long j = i*i; j <= k; j += i) {
				visited.at(j - 2) = false;
			}
		}
	}
	
	long prime = 2;
	// All prime numbers are true.
	for(const bool& v : visited) {
		if(v == true) {
			primes.push_back(prime);
		}
		++prime;
	}

	return primes;
}

int main() {
	std::vector<long> primes = generatePrimes(2000000);
	
	long sum = 0;
	for(const long& p : primes) {
		sum += p;
	}
	std::cout << sum << '\n';

	return 0;
}
