#include <iostream>
#include <stdio.h>
#include <algorithm>

#ifdef LOCAL
    const int MAX = 10;
#else
    const int MAX = 101;
#endif

int main() {
    int R, S, P;
    scanf("%d %d %d", &R, &S, &P);

    long double mem[MAX][MAX][MAX];
    for(int i = 0; i < MAX; ++i) for(int j = 0; j < MAX; ++j) for(int k = 0; k < MAX; ++k)
        mem[i][j][k] = 0;
    mem[R][S][P] = 1;

    for(int sum = R+S+P; sum > 0; --sum) {
        for(int r = R; r >= 0; --r) {
            for(int s = S; s >= 0; --s) {
                int p = sum - s - r;
                if(p < 0 || p > P) continue;
                if(std::min(1, r) + std::min(1, s) + std::min(1, p) <= 1) continue; // only one alive

                long double c = mem[r][s][p];

                int total_comb = r * s + s * p + r * p;
                if(r > 0) mem[r-1][s][p] += c * r * p / total_comb;
                if(s > 0) mem[r][s-1][p] += c * r * s / total_comb;
                if(p > 0) mem[r][s][p-1] += c * p * s / total_comb;
            }
        }
    }

    long double r = 0;
    long double s = 0;
    long double p = 0;
    for(int i = 1; i <= R; ++i) r += mem[i][0][0];
    for(int i = 1; i <= S; ++i) s += mem[0][i][0];
    for(int i = 1; i <= P; ++i) p += mem[0][0][i];

    printf("%.12f %.12f %.12f\n", (double) r, (double) s, (double) p);
}
