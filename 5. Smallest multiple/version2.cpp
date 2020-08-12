// https://projecteuler.net/problem=5

/* The key parts of this algorithm are:
 * 1. You should have already an array of prime numbers to be iterated.
 * 2. using log to get how many times that prime number is repeated.
 *
 * With this, there is no need to check if the number is prime or not, we only care
 * to obtain how many times that prime number is repeated to do the corresponding operation.
 * */


#include <iostream>
#include <vector>
#include <cmath>
 
// Sieve of Eratosthenes https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
std::vector<long> generatePrimes(long k) {
	k = k * k; // To have enough space, not efficient, I will have primes numbers I'll never use.
	std::vector<bool> foundPrimes(k, true);
	std::vector<long> primes;

	for(long i = 2; i <= k; i++) {
		if(foundPrimes.at(i - 2) == false) {
			continue;
		}

		for(long j = i + 1; j <= k; j++) {
			if(j % i == 0) {
				foundPrimes.at(j - 2) = false;	
			}
		}	
		primes.push_back(i);
	}
	return primes;
}

int main() {
	// Just a direct transcription from the pdf.
	long k = 10;
	long N = 1;
	long i = 0;
	std::vector<long> primes = generatePrimes(k);
	std::vector<long> countNumbers(k, 0);
	bool check = true;
	long limit = sqrt(k);

	while(primes.at(i) <= k) {
		// Assume that prime number only repeats once.
		countNumbers.at(i) = 1;
		if(check) {
			// The prime number repeats multiple times.
			if(primes.at(i) <= limit) {
				countNumbers.at(i) = log(k) / log(primes.at(i)); // Get how many times the prime number is repeated.
			} else {
				check = false;
			}
		}
		N = N * pow(primes.at(i), countNumbers.at(i));
		i++;
	}

	std::cout << N << '\n';
	return 0;
}
