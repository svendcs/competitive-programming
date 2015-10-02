#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	int n; scanf("%d", &n);
	int houses[n];
	int highest[n+1];
	highest[n] = 0;

	for(int i = 0; i < n; ++i) {
		scanf("%d", &houses[i]);
	}


	for(int i = n-1; i >= 0; --i) {
		highest[i] = std::max(highest[i+1], houses[i]);
	}

	for(int i = 0; i < n; ++i) {
		int needed = (highest[i+1] < houses[i] ? 0 : highest[i+1] - houses[i] + 1);
		printf("%d ", needed);
	}
		printf("\n");
	return 0;
}
