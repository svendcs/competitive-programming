#include <iostream>

void solve() {
	int villages[20];
	for(int i = 0; i < 20; ++i) {
		std::cin >> villages[i];
	}

	for(int i = 19; i > 0; --i) {
		if(villages[i] % 2 == 0) {
			villages[i-1] += villages[i]/2;
			villages[i] = 0;
		}
		else {
			villages[i-1] += villages[i]/2;
			villages[i] = 1;
		}
	}

	for(int i = 0; i <20; ++i) {
		std::cout << villages[i] << " ";
	}
	std::cout << std::endl;
}
int main() {
	int n; std::cin >> n;
	for(int i = 0; i < n; ++i) solve();
	return 0;
}
