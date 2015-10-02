#include <iostream>
#include <algorithm>

int main() {
	int a, b;
	std::cin >> a >> b;
	
	int d = std::max(a,b) - std::min(a,b);
	d = d/2;
	std::cout << std::min(a, b) << " " << d << std::endl;
	return 0;
}
