// https://projecteuler.net/problem=2

/* 1 1 2 3 5 8 13 21 34 55 89 144 ...
 * a b c a b c a b c a b c a  c  
 *
 * Every third Fibonaccy number is even, just every thid numer added.
 * */

#include <iostream> 

int main() {
	int a{1}, b{1}, c{0}, sum{0};

	c = a + b;
	while(c < 4000000) {
		sum = sum + c;
		a = b + c;
		b = c + a;
		c = a + b;
	}
	std::cout << sum << " ";

	return 0;
}
