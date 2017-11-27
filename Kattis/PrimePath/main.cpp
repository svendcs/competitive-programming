#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

int clear_digit(int n, size_t i) {
    int pow = std::pow(10, i);
    int digit = (n / pow) % 10;

    return n - digit * pow;
}

int main() {
     bool prime[10000];
     std::fill(std::begin(prime), std::end(prime), true);

     prime[0] = false;
     for (size_t i = 2; i <= 9999; ++i) {
         if (!prime[i]) continue;
         for (size_t j = 2 * i; j <= 9999; j += i)
             prime[j] = false;
     }

     size_t n; std::cin >> n;
     bool visited[10000];
     for (size_t c = 0; c < n; ++c) {
         int a, b;
         std::cin >> a >> b;

         std::fill(std::begin(visited), std::end(visited), false);
         std::queue<std::pair<size_t, int>> q;

         q.push(std::make_pair(0, a));
         visited[a] = true;

         while (!q.empty()) {
             auto e = q.front();
             q.pop();

             if (e.second == b) {
                 std::cout << e.first << std::endl;
                 break;
             }


             // change right most digit
             for (size_t i = 0, j = clear_digit(e.second, 0); i <= 9; ++i, j += 1) {
                 if (j == e.second) continue;

                 if (!prime[j]) continue;
                 if (visited[j]) continue;

                 visited[j] = true;
                 q.push(std::make_pair(e.first+1, j));
             }

             for (size_t i = 0, j = clear_digit(e.second, 1); i <= 9; ++i, j += 10) {
                 if (j == e.second) continue;

                 if (!prime[j]) continue;
                 if (visited[j]) continue;

                 visited[j] = true;
                 q.push(std::make_pair(e.first+1, j));
             }

             for (size_t i = 0, j = clear_digit(e.second, 2); i <= 9; ++i, j += 100) {
                 if (j == e.second) continue;

                 if (!prime[j]) continue;
                 if (visited[j]) continue;

                 visited[j] = true;
                 q.push(std::make_pair(e.first+1, j));
             }

             for (size_t i = 1, j = clear_digit(e.second, 3)+1000; i <= 9; ++i, j += 1000) {
                 if (j == e.second) continue;

                 if (!prime[j]) continue;
                 if (visited[j]) continue;

                 visited[j] = true;
                 q.push(std::make_pair(e.first+1, j));
             }
         }
     }
}
