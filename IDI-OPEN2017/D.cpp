#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
	for (int j = 0; j < w[i].size(); j++) {
		if (w[i][j] && !seen[j]) {
			seen[j] = true;
			if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
				mr[i] = j;
				mc[j] = i;
				return true;
			}
		}
	}
	return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
	mr = VI(w.size(), -1);
	mc = VI(w[0].size(), -1);

	int ct = 0;
	for (int i = 0; i < w.size(); i++) {
		VI seen(w[0].size());
		if (FindMatch(i, w, mr, mc, seen)) ct++;
	}
	return ct;
}

int fact(int n) {
	if (n == 0) return 1;
	return fact(n - 1) * n;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<string> words(M);
	for (auto & w : words) {
		cin >> w;
	}

	vector<string> dies(N);
	vector<vector<bool>> has(N, vector<bool>(256));
	int i = 0;
	for (auto & d : dies) {
		cin >> d;
		if (d.find('*') != string::npos) {
			has[i] = vector<bool>(256, true);
		} else {
			for (char c : d) {
				has[i][(unsigned char)c] = true;
			}
		}
		i++;
	}

	int result = 0;

	for (int i = 1; i < (1 << M); i++) {
		int subsize = 0;
		int poem_length = 0;
		string poem = "";
		for (int j = 0; j < M; j++) {
			if ((1 << j) & i) {
				poem += words[j];
				poem_length += words[j].size();
				subsize++;
			}
		}

		if (poem_length > N) {
			continue;
		}

		VVI w(poem_length, VI(N));

		for (int i = 0; i < poem_length; i++) {
			for (int j = 0; j < N; j++) {
				w[i][j] = has[j][(unsigned char)poem[i]];
			}
		}

		VI mr, mc;

		int m = BipartiteMatching(w, mr, mc);

		if (m == poem_length) {
			result += fact(subsize);
		}
	}

	cout << result << "\n";
}
