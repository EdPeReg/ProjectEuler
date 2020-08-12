// https://projecteuler.net/problem=5

/* We start from 20 because we will divide from 2-20, (1 is not taken in consideration because any number divided by 1
 * will always yield a remainder 0), if our number is 15, any number above that will be invalid (we need to reach 20, is our limit).
 *
 * We start like this:
 * 20 % 2 = 0
 * 20 % 3 = 2 -> We increment 20 by 1 and we will start again from 1-20.
 *
 * 21 % 2 = 1 -> Increment 21 by 1 and start again from 1.
 *
 * We continue doing this until we find a number that is divisible from 2-20, once we
 * hit 20, we stop. */

#include <iostream>

int main() {
	long num = 2, num2 = 20;
	while(num <= 20) {
		if(num2 % num != 0) {
			++num2;
			num = 1;
		} else {
			++num;
		}
	}

	std::cout << num2 << '\n';

	return 0;
}
