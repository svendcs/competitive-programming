#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;

#define SQR(x) ((x) * (x))

int A, F, L, W;
pair<int, int> start, goal;
int start_i, goal_i;

vector<pair<int, int>> nodes;

int bfs(vector<vector<int>> & adj) {
	queue<pair<int, int>> Q;
	Q.push({start_i, 0});
	unordered_set<int> visited;

	while (!Q.empty()) {
		auto p = Q.front();
		Q.pop();

		int i = p.first;
		int d = p.second;

		if (i == goal_i) {
			return d;
		}

		if (visited.count(i)) {
			continue;
		}

		visited.insert(i);

		for (int j : adj[i]) {
			Q.push({j, d + 1});
		}
	}

	return INT_MAX;
}

int main() {
	cin >> A >> F >> L >> W;


	for (int i = 0; i < L; i++) {
		string l;
		cin >> l;
		for (int j = 0; j < W; j++) {
			if (l[j] == 'B') continue;

			if (l[j] == 'S') {
				start = {i, j};
				start_i = nodes.size();
			} else if (l[j] == 'G') {
				goal = {i, j};
				goal_i = nodes.size();
			}

			nodes.push_back({i, j});
		}
	}

	int N = nodes.size();

	vector<vector<int>> adj1(N);
	vector<vector<int>> adj2(N);

	for (int i = 0; i < N; i++) {
		auto & n1 = nodes[i];
		for (int j = i + 1; j < N; j++) {
			auto & n2 = nodes[j];
			double dist = sqrt(SQR(n1.first - n2.first) + SQR(n1.second - n2.second));

			if (dist <= A) {
				adj1[i].push_back(j);
				adj1[j].push_back(i);
			}

			if (n1.first == n2.first || n1.second == n2.second) {
				if (dist <= F) {
					adj2[i].push_back(j);
					adj2[j].push_back(i);
				}
			}
		}
	}

	int d1 = bfs(adj1);
	int d2 = bfs(adj2);

	//cout << d1 << ", " << d2 << "\n";

	if (d1 == d2) {
		if (d1 == INT_MAX) {
			cout << "NO WAY\n";
		} else {
			cout << "SUCCESS\n";
		}
	} else {
		if (d1 < d2) {
			cout << "GO FOR IT\n";
		} else {
			cout << "NO CHANCE\n";
		}
	}

}
