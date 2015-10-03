#include <iostream>

int mem[14][14][5][3];
int array[14];

bool dp(int a, int b, int pairs_required, int trip_required) {
	if(pairs_required == 0 && trip_required == 0)
		return true;
	if(a >= b)
		return false;

	if(mem[a][b][pairs_required][trip_required] != -1)
		return mem[a][b][pairs_required][trip_required] == 1;
	bool res = false;
	if(pairs_required > 0) {
		for(int i = a; i < b; ++i) {
			if(array[i] == array[i+1]) {
				res = res || dp(a, i-1, pairs_required-1, trip_required)  || dp(i+2, b, pairs_required-1, trip_required);
			}
		}
	}

	if(trip_required > 0) {
		for(int i = a; i < b-1; ++i) {
			if((array[i] == array[i+1] && array[i] == array[i+2]) || (array[i] == array[i+1] - 1 && array[i+1] == array[i+2] - 1)) {
				res = res || dp(a, i-1, pairs_required, trip_required-1)  || dp(i+3, b, pairs_required, trip_required-1);
			}
		}
	}

	/* res = res || dp(a+1,b,pairs_required,trip_required); */

	if(res)
		mem[a][b][pairs_required][trip_required] = 1;
  	mem[a][b][pairs_required][trip_required] = 0;
	return res;
}

bool solve() {
	for(int i = 0; i < 14; ++i) {
		std::cin >> array[i];
	}


	for(int i = 0; i < 14; ++i) for(int j = 0; j < 14; ++j) for(int k = 0; k <= 4; ++k) for(int l = 0; l <= 2; ++l)
		mem[i][j][k][l] = -1;

	return dp(0, 13, 1, 4);
}

int main() {
	int n; std::cin >> n;
	for(int i = 0; i < n; ++i) {
		std::cout << (solve() ? "Vulnerable" : "Immune") << std::endl;
	}
	return 0;
}
