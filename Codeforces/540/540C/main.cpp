#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>

bool inside(int r, int c, int rows, int columns) {
    return (0 <= r && r < rows) && (0 <= c && c < columns);
}
    
int main() {
    char map[500][500]; // (row, column) format
    int r1, r2, c1, c2;
    int rows, columns;

    scanf("%d %d", &rows, &columns);
    for(int i = 0; i < rows; ++i)
        scanf("%s", map[i]);

    scanf("%d %d", &r1, &c1); --r1; --c1;
    scanf("%d %d", &r2, &c2); --r2; --c2;

    std::queue<std::pair<int, int>> queue;
    bool path_clear = false;

    queue.push(std::make_pair(r1, c1));
    bool visited[500][500]; std::fill(&visited[0][0], &visited[0][0] + sizeof(visited), false);
    while(!queue.empty() && !path_clear) {
        auto p = queue.front(); queue.pop();

        if(p.first == r2 && p.second == c2) {
            path_clear = true;
            break;
        }

        for(int i = -1; i <= 1; i += 1) for(int j = -1; j <= 1; j += 1) {
            if(i == 0 && j == 0) continue;
            if(i != 0 && j != 0) continue;
            int r = p.first + i;
            int c = p.second + j;
            if(!inside(r, c, rows, columns))
                continue;
            
            if(map[r][c] == 'X' && !(r == r2 && c == c2))
                continue;

            if(visited[r][c])
                continue;

            visited[r][c] = true;

            queue.push(std::make_pair(r, c));
        }
    }

    if(!path_clear) {
        std::cout << "NO" << std::endl;
    }
    else if(map[r2][c2] == 'X' && !(r1 == r2 && c1 == c2))
        std::cout << "YES" << std::endl;
    else {
        int count = 0;
       for(int i = -1; i <= 1; ++i) for(int j = -1; j <= 1; ++j) {
            if(i == 0 && j == 0) continue;
            if(i != 0 && j != 0) continue;
            int r = r2 + i;
            int c = c2  + j;
            if(!inside(r, c, rows, columns))
                continue;

            if(map[r][c] == '.') {
                ++count;
            }
       }

       if(std::abs(c2-c1)+std::abs(r2-r1) <= 1)
           std::cout << (count >= 1 ? "YES" : "NO") << std::endl;
       else
           std::cout << (count >= 2 ? "YES" : "NO") << std::endl;
    }
}
