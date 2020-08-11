// https://projecteuler.net/problem=4

/* The minimum and maximum number of 3 digits it's 100 and 999.
 * - We multiple both numbers:
 *   	100 * 100
 *   	100 * 1001
 *   	100 * 1002
 *   	100 * 1003
 *   		.
 *   		.
 *   		.
 *   	1001 * 100
 *   	1001 * 1001
 *   	1002 * 1002
 *   		.
 *   		.
 *   		.
 *
 * - Evaluate if the number yielded is a palindromic Number and store it in the vector.
 * - Find the largest palindromic number from the vector. 
 *   The comparation a <= b makes you to not repeat multiplications. Doing only the half of the computations. */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
	std::vector<int> palindromicNumbers;
	int n1{999};
	int n2{999};

	while(n1 >= 100) {
		// We don't want to repeat multiplications.
		if(n1 <= n2) {
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
				std::cout << "n1 * n2: " << n1 << " " << n2 << '\n';
				std::cout << n1 * n2 << '\n';
				palindromicNumbers.push_back(n1 * n2);
			}
		}

		--n2;
		if(n2 < 100) {
			--n1;
			n2 = 999;
		}
	}

	//for(auto p : palindromicNumbers) {
		//std::cout << p << '\n';
	//}
	std::cout << *std::max_element(palindromicNumbers.begin(), palindromicNumbers.end());
	return 0;
}
