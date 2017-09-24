#include <queue>
#include <iostream>
#include <algorithm>

struct entry {
    int x;
    int y;
    char type;
    int time;
};

int main() {
    int rows, columns;
    std::cin >> rows >> columns;
    
    char maze[1001][1001];
    bool fire_visited[1001][1001];
    bool joe_visited[1001][1001];
    for(int i = 0; i < rows; ++i)
        std::cin >> maze[i];

    std::vector<std::pair<int, int>> fire_pos;
    int joe_x, joe_y;

    for(int y = 0; y < rows; ++y) {
        for(int x = 0; x < columns; ++x) {
            joe_visited[y][x] = false;
            fire_visited[y][x] = false;
            if (maze[y][x] == 'J') {
                joe_x = x;
                joe_y = y;
            }
            if (maze[y][x] == 'F') {
                fire_pos.push_back(std::make_pair(x, y));
            }
        }
    }

    std::queue<entry> queue;
    for (auto pos : fire_pos) {
        queue.push({pos.first, pos.second, 'F', 0});
        fire_visited[pos.second][pos.first] = true;
    }
    queue.push({joe_x, joe_y, 'J', 0});

    joe_visited[joe_y][joe_x] = true;

    while (!queue.empty()) {
        auto e = queue.front();
        queue.pop();

        if (e.type == 'J') {
            for (int new_x = e.x-1; new_x <= e.x+1; new_x += 2) {
                if (new_x == -1 || new_x == columns) {
                    std::cout << e.time + 1 << std::endl;
                    return 0;
                }

                if (maze[e.y][new_x] == '#') continue;
                if (joe_visited[e.y][new_x]) continue;
                if (fire_visited[e.y][new_x]) continue;

                joe_visited[e.y][new_x] = true;
                queue.push({new_x, e.y, 'J', e.time+1});
            }
            for (int new_y = e.y-1; new_y <= e.y+1; new_y += 2) {
                if (new_y == -1 || new_y == rows) {
                    std::cout << e.time + 1 << std::endl;
                    return 0;
                }

                if (maze[new_y][e.x] == '#') continue;
                if (joe_visited[new_y][e.x]) continue;
                if (fire_visited[new_y][e.x]) continue;

                joe_visited[new_y][e.x] = true;
                queue.push({e.x, new_y, 'J', e.time+1});
            }
        }
        if (e.type == 'F') {
            for (int new_x = e.x-1; new_x <= e.x+1; new_x += 2) {
                if (new_x == -1 || new_x == columns) {
                    continue;
                }

                if (maze[e.y][new_x] == '#') continue;
                if (fire_visited[e.y][new_x]) continue;

                fire_visited[e.y][new_x] = true;
                queue.push({new_x, e.y, 'F', e.time+1});
            }
            for (int new_y = e.y-1; new_y <= e.y+1; new_y += 2) {
                if (new_y == -1 || new_y == rows) {
                    continue;
                }

                if (maze[new_y][e.x] == '#') continue;
                if (fire_visited[new_y][e.x]) continue;

                fire_visited[new_y][e.x] = true;
                queue.push({e.x, new_y, 'F', e.time+1});
            }
        }
    }

    std::cout << "IMPOSSIBLE" << std::endl;

    return 0;
}
