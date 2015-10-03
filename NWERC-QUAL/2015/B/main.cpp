#include <iostream>

double calc(int m1, int y1, int m2, int y2) {
	/* std::cout << m1 << " " << y1 << " " << m2 << " " << y2 << std::endl; */
	if(y1 == y2) {
		double per = 0.5 / (12-m1+1);
		return per * (m2-m1);
	}
	double res = 0.5;
	res += y2-y1-1;
	res += ((double) 1.0 / 12.0) * (m2-1);
	
	return res;
}

int main() {
	int n; std::cin >> n;
	for(int i = 0; i < n; ++i) {
		int m1, y1, m2, y2;
		std::cin >> m1 >> y1 >> m2 >> y2;
		std::cout.precision(4);
		std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		std::cout << calc(m1, y1, m2, y2) << std::endl;
	}
	return 0;
}
