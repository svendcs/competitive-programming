#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

void solve() {
	int width, height;
	std::cin >> width >> height;

	std::vector<std::string> map;
	for(int i = 0; i < height; ++i) {
		std::string tmp;
		std::cin >> tmp;
		map.push_back(tmp);
	}

	bool caused[height][width];
	int n; std::cin >> n;
	for(int i = 0; i < n; ++i) {
		int x, y; std::cin >> x >> y;

		if(map[y][x] == 'X') continue;
		if(map[y][x] != 'D') {
			map[y][x] += 1;
			continue;
		}

		// else
		for(int j = 0; j < height; ++j)  {
			for(int k = 0; k < width; ++k) {
				caused[j][k] = false;
			}
		}

		std::queue<std::pair<int,int>> queue;
		queue.push(std::make_pair(x, y));

		while(!queue.empty()) {
			auto el = queue.front(); queue.pop();
			int x1 = el.first;
			int y1 = el.second;

			if(map[y1][x1] == 'X') continue;
			if(map[y1][x1] != 'D') {
				map[y1][x1] += 1;
				continue;
			}

			if(caused[y1][x1]) continue;
			caused[y1][x1] = true;

			// else cause outbreak
			if(x1 > 0) {queue.push(std::make_pair(x1-1,y1));}
			if(y1 > 0) {queue.push(std::make_pair(x1,y1-1));}
			if(x1 < width-1) {queue.push(std::make_pair(x1+1,y1));}
			if(y1 < height-1) {queue.push(std::make_pair(x1,y1+1));}
		}

	}

	for(int j = 0; j < height; ++j) {
		std::cout << map[j] << std::endl;
	}

}
int main() {
	int n; std::cin >> n;
	for(int i = 0; i < n; ++i) solve();

}
