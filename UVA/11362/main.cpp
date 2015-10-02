#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool is_prefix(std::string a, std::string b) {
	if(a.size() > b.size()) return false;
	for(int i = 0; i < a.size(); ++i) {
		if(a[i] != b[i]) return false;
	}

	return true;
}

bool test_case() {
	int n; std::cin >> n;
	std::vector<std::string> numbers;
	for(int i = 0; i < n; ++i) {
		std::string tmp; std::cin >> tmp;
		numbers.push_back(tmp);
	}

	std::sort(numbers.begin(), numbers.end());
	for(int i = 1; i < n; ++i) {
		if(is_prefix(numbers[i-1], numbers[i]))
			return false; // list is not consistent
	}

	return true;
}

int main() {
	int n; std::cin >> n;
	for(int i = 0; i < n; ++i)
		std::cout << (test_case() ? "YES" : "NO") << std::endl;
	return 0;
}
