#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::pair<int, int>> day_list;

int max_height(day_list notes, int days) {
    int a = notes.back().second + days - notes.back().first;
    int b = notes.front().second + notes.front().first - 1;
    int res = std::max(a, b);

    for(int i = 0; i < notes.size() - 1; ++i) {
        int hdiff = std::abs(notes[i].second - notes[i+1].second);
        int ddiff = notes[i+1].first - notes[i].first;
        if(hdiff > ddiff)
            return -1;

        int a = std::max(notes[i].second, notes[i+1].second) + (ddiff - hdiff) / 2;
        res = std::max(a, res);
    }

    return res;
}

int main() {
    day_list notes;
    int days, n;

    std::cin >> days >> n;
    for(int i = 0; i < n; ++i) {
        int a, b; std::cin >> a >> b;
        notes.push_back(std::make_pair(a, b));
    }

    int res = max_height(notes, days);
    if(res == -1)
        std::cout << "IMPOSSIBLE" << std::endl;
    else
        std::cout << res << std::endl;
}
