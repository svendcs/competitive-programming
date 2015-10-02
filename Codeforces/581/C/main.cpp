#include <stdio.h>
#include <iostream>
#include <algorithm>

int main() {
	size_t n, k;
	std::cin >> n >> k;
	size_t skills[n];

	for(size_t i = 0; i < n; ++i)
		std::cin >> skills[i];

	size_t current_skill = 0;
	for(size_t i = 0; i < n; ++i) {
		current_skill += skills[i]/10;	
	}

	for(size_t i = 9; i >= 1; --i) {
		for(size_t j = 0; j < n; ++j) {
			if(k < 10-i) break;
			if(skills[j] % 10 == i) {
				current_skill += 1;
				k -= 10-i;
				skills[j] += 10-i;
			}
		}
	}

	size_t max_possible = n * 10;
	std::cout << std::min(current_skill + k / 10, max_possible) << std::endl;

	return 0;
}
