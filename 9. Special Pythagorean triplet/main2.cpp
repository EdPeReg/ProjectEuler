// https://projecteuler.net/problem=9

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

struct Triplet { 
	int a, b, c;
};

std::vector< std::pair<int, int> > getFactorPairs(int r) {
	std::vector< std::pair<int, int> > factorPairs;
	std::pair<int, int> pairs;
	for(int i = 1; i < sqrt(r); ++i) {
		if(r % i == 0) {
			pairs.first = i;
			pairs.second = r / i;
			factorPairs.push_back(pairs);
		}
	}

	return factorPairs;
}

// Will generate ALL the triplets, using Dickson's method. 
// https://en.wikipedia.org/wiki/Formulas_for_generating_Pythagorean_triples
std::vector<Triplet> generateTriplets(int r) {
	std::vector<Triplet> triplets;
	std::vector< std::pair<int, int> > factorPairs = getFactorPairs(pow(r,2) / 2);

	for(std::vector< std::pair<int, int> >::iterator it = factorPairs.begin(); it != factorPairs.end(); ++it) {
		Triplet triplet;
		int s = it->first;
		int t = it->second;
		
		triplet.a = r + s;
		triplet.b = r + t;
		triplet.c = r + s + t;
		triplets.push_back(triplet);
	}

	return triplets;
}

int main() {
	int i = 2, sum = 0;
	bool end = false;
	while(!end) {
		std::vector<Triplet> triplets = generateTriplets(i);

		for(const Triplet& triplet : triplets) {
			std::cout << "triplet: " << "(" << triplet.a << "," << triplet.b << "," << triplet.c << ")" << '\n';
			sum = triplet.a + triplet.b + triplet.c;
			std::cout << "sum: " << sum << '\n';

			if(sum == 1000) {
				std::cout << "a*b*c: " << triplet.a * triplet.b * triplet.c << '\n';
				end = true;
			}
		}
		i += 2;
	}

	return 0;
}

