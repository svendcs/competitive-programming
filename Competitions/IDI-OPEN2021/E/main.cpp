#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MAXS = 11;
using T = ll;
const T INF = 1e12;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x).size()

#define repbits(x, bs) for (int x, y = bs; y && ((x = __builtin_ctz(y)) || y); y^= y&-y)

T DP[1 << MAXS][MAXS];

T * TSP(const vector<vector<T>> &C) {
  int S = sz(C)-1, M=1<<S;
  rep(i, 0, S) DP[1 << i][i] = C[S][i];
  rep(bs, 3, M) if(__builtin_popcount(bs) > 1) repbits(j, bs) {
    int nbs = bs ^ (1 << j); T& r=DP[bs][j] = INF;
    repbits(i, nbs) r = min(r, DP[nbs][i] + C[i][j]);
  }

  return DP[M-1];
}

std::vector<std::vector<long long>> dist;
int n, v, e;

int main() {
  std::cin >> n >> v >> e;

  for (int i = 0; i < v; ++i) {
    dist.push_back(std::vector<long long>(v, INF));
    dist[i][i] = 0;
  }

  // Read edges
  for (int i = 0; i < e; ++i) {
    int u, v;
    long long w;
    std::cin >> u >> v >> w;
    dist[u][v] = std::min(w, dist[u][v]);
    dist[v][u] = std::min(w, dist[v][u]);
  }

  if (n == 1) {
    std::cout << 0 << std::endl;
    return 0;
  }

  // Run floyd warshall
  for (int k = 0; k < v; ++k) {
    for (int i = 0; i < v; ++i) {
      for (int j = 0; j < v; ++j) {
        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  std::vector<std::vector<long long>> distances;
  for (int i = 0; i < n; ++i) {
    distances.emplace_back();
    for (int j = 0; j < n; ++j) {
      distances[i].push_back(dist[i][j]);
    }
  }


  auto res = TSP(distances);
  ll sol = INF;
  for (int i = 0; i < n-1; ++i) {
    // std::cout << res[i] << std::endl;
    ll cur = res[i] + distances[i][n-1];
    sol = min(cur, sol);
  }

  std::cout << sol << std::endl;
}

