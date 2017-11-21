#include <iostream>
#include <queue>

struct QueueEntry {
    int y, x, height;

    bool operator<(const QueueEntry & other) const {
        return height > other.height;
    }
};

int main() {
    int h, w; std::cin >> h >> w;

    int map[h][w];
    int drained[h][w];
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            std::cin >> map[y][x];
            drained[y][x] = 0;
        }
    }

    int y, x; std::cin >> y >> x;
    --y; --x;

    std::priority_queue<QueueEntry> queue;
    queue.push({y, x, map[y][x]});
    drained[y][x] = map[y][x];

    int res = 0;
    while (!queue.empty()) {
        auto e = queue.top();
        // std::cout << "Visit y=" << e.y << ", x=" << e.x << ", height=" << e.height << std::endl;
        queue.pop();

        if (drained[e.y][e.x] < e.height) continue;
        res += -e.height;

        for (int ym = e.y -1; ym <= e.y + 1; ++ym) {
            for (int xm = e.x -1; xm <= e.x + 1; ++xm) {
                if (ym == e.y && xm == e.x) continue;
                if (!(0 <= ym && ym < h)) continue;
                if (!(0 <= xm && xm < w)) continue;
                if (map[ym][xm] >= 0) continue;

                int new_height = std::max(e.height, map[ym][xm]);
                if (drained[ym][xm] <= new_height) continue;
                // std::cout << "Adding " << ym << " " << xm << " " << new_height << std::endl;

                queue.push({ym, xm, new_height});
                drained[ym][xm] = new_height;
            }
        }
    }

    std::cout << res << std::endl;

}
