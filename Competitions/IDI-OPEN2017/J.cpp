#include <iostream>
#include <array>
#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <climits>

using namespace std;

typedef double T;
const T EPS = 1e-7;

struct PT {
	T x, y;
	PT() {}
	PT(T x, T y) : x(x), y(y) {}
	bool operator<(const PT &rhs) const { return make_pair(y, x) < make_pair(rhs.y, rhs.x); }
	bool operator==(const PT &rhs) const { return make_pair(y, x) == make_pair(rhs.y, rhs.x); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

void ConvexHull(vector<PT> &pts) {
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());
	vector<PT> up, dn;
	for (int i = 0; i < pts.size(); i++) {
		while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
		while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
		up.push_back(pts[i]);
		dn.push_back(pts[i]);
	}
	pts = dn;
	for (int i = up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

struct item {
	int t;
	double m;
	double density() const {
		return m / t;
	}
	bool operator<(const item & o) const {
		return density() < o.density();
	}
};

int main() {
	int N, M;
	cin >> N >> M;

	vector<array<int, 2>> trees(N);
	for (auto & t : trees) {
		cin >> t[0] >> t[1];
	}

	vector<PT> points(M);
	for (auto & p : points) {
		cin >> p.x >> p.y;
	}

	ConvexHull(points);

	double len = 0;
	for (int i = 0; i < points.size(); i++) {
		double dx = points[i].x - points[(i + 1) % points.size()].x;
		double dy = points[i].y - points[(i + 1) % points.size()].y;
		len += sqrt(dx*dx + dy*dy);
	}

	//cout << len << "\n";


	vector<vector<int>> min_time(6000, vector<int>(N+1, -1));

	for (int length = 0; length < 6000; length++) {
		for (int i = N; i >= 0; i--) {
			if (length == 0) {
				min_time[length][i] = 0;
			}
			else if (i == N) {
				min_time[length][i] = -1;

			} else {
				auto & t = trees[i];

				int new_length = std::max(0, length - t[0]);
				auto & dp =min_time[length][i];
				dp = -1;
				if (min_time[length][i+1] != -1)
					dp =min_time[length][i+1];
				if (min_time[new_length][i+1] != -1) {
					auto a =min_time[new_length][i+1] + t[1];
					if (dp == -1 || a < dp)
						dp = a;
				}
			}
		}
	}

	//cout << len << endl;
	cout << min_time[ceil(len)][0] << std::endl;

	/*
	vector<int> min_time(6000, -1);
	min_time[0] = 0;

	int best = INT_MAX;

	for (int i = 1; i < 6000; i++) {
		for (auto & t : trees) {
			int length = t[0];
			int time = t[1];

			if (length <= i) {
				int t = min_time[i - length];
				if (t != -1) {
					if (min_time[i] == -1 || min_time[i] > t + time) {
						min_time[i] = t + time;
						if (i >= len) {
							best = min(best, t + time);
						}
					}
				}
			}
		}
	}
	*/

	/*
	priority_queue<item> Q;

	for (auto & t : trees) {
		Q.push({t[1], double(t[0])});
	}

	int time = 0;
	while (len > 0) {
		auto item = Q.top();
		//cout << item.density() << "\n";
		Q.pop();
		if (item.m <= len) {
			//cout << "use\n";
			time += item.t;
			len -= item.m;
		} else {
			//cout << "skip\n";
			item.m = len;
			Q.push(item);
		}
	}

	cout << time << "\n";
	*/
}
