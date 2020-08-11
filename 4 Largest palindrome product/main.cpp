// https://projecteuler.net/problem=4

/* The minimum and maximum number of 3 digits it's 100 and 999.
 * - We multiple both numbers:
 *   	100 * 100
 *   	100 * 101
 *   	100 * 102
 *   	100 * 103
 *   		.
 *   		.
 *   		.
 *   	101 * 100
 *   	101 * 101
 *   	102 * 102
 *   		.
 *   		.
 *   		.
 *
 * - Evaluate if the number yielded is a palindromic Number and store it in the vector.
 * - Find the largest palindromic number from the vector. */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
	std::vector<int> palindromicNumbers;
	int n1{100};
	int n2{100};

	while(n1 <= 999) {
		std::string strNumber = std::to_string(n1 * n2);
		
		int rightPos = strNumber.size() - 1;
		bool palindromicNumber = false;
		for(size_t leftPos = 0; leftPos < strNumber.size(); leftPos++) {
			if(strNumber[leftPos] == strNumber[rightPos]) {
				palindromicNumber = true;
				--rightPos;
			} else {
				palindromicNumber = false;
				break;
			}
		}

		if(palindromicNumber) {
			palindromicNumbers.push_back(n1 * n2);
		}

		++n2;
		if(n2 > 999) {
			++n1;
			n2 = 100;
		}
	}

	std::cout << *std::max_element(palindromicNumbers.begin(), palindromicNumbers.end());
	return 0;
}
