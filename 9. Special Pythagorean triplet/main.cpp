// https://projecteuler.net/problem=9

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

// 1. Generate pythagorean triplet using the formula (looping)
// 2. check condition and stop

struct Triplet {
	int a, b, c;
};

// Table method. https://en.wikipedia.org/wiki/Least_common_multiple
int lcm(int m, int n) {
	int result = 1;
	int num = 2;
	while(m != 1 or n != 1) {
		if(n % num != 0 and m % num != 0) {
			++num;
		} else {
			if(m % num == 0) {
				m /= num;
			} 

			if(n % num == 0) {
				n /= num;
			}
			result *= num;
		}
	}
	return result;
}

int gcd(int m, int n) {
	int result = (abs(m*n)) / lcm(m,n); 
	return result;
}

bool isCoprime(int m, int n) {
	return gcd(m, n) == 1;
}

// Using Euclid's Formula.
Triplet generatePythagoreanTriplet(int m, int n) {
	Triplet triplet;
	triplet.a = pow(m, 2) - pow(n, 2);
	triplet.b = 2 * m * n;
	triplet.c = pow(m, 2) + pow(n, 2);
	return triplet;
}

int main() {
	std::vector<Triplet> triplets;

	//for(int m = 2; m <= 501; ++m) {
		//for(int n = 1; n < m; ++n) {
			//if(isCoprime(m, n) and ((m-n) % 2 == 1)) {
				//triplets.push_back(generatePythagoreanTriplet(m,n));
			//}
		//}
	//}

	//for(auto t : triplets) {
		//std::cout << t.a << " " << t.b << " " << t.c << '\n';
		//std::cout << "sum: " << t.a + t.b + t.c << '\n';
	//}

	int n = 1, m = 2, sum = 0; 
	// I cant get a + b + c = 1000.
	while(sum < 1000) {
		if(m > n) {
			// To generate triple primitive.
			if(isCoprime(m, n) and ((m - n) % 2 == 1))	{
				triplets.push_back(generatePythagoreanTriplet(m, n));
				std::cout << triplets.at(n - 1).a << " " << triplets.at(n - 1).b << " " << triplets.at(n - 1).c << '\n';
				sum = triplets.at(n - 1).a + triplets.at(n - 1).b + triplets.at(n - 1).c;
				std::cout << "sum: " << sum << '\n';
				++n;
				++m;
			}
		}
	}

	return 0;
}
