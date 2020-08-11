// https://projecteuler.net/problem=2

#include <iostream> 

int main() {
	int a{0}, b{1}, c{0}, sum{0};

	while(true) {
		c = a + b;
		if(c > 4000000) {
			break;
		}
		if(c % 2 == 0) {
			sum += c;
		}
		a = b;
		b = c;
	}
	std::cout << sum << " ";

	return 0;
}
