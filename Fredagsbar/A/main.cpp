#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

int main() {
    size_t w, h, b, n;
    std::cin >> w >> h >> b >> n;
    char map[w][h];
    double score[w][h];
    for(size_t i = 0; i < w; ++i) {
        for(size_t j = 0; j < h; ++j)
            score[i][j] = 0;
    }
    std::string blah;
    std::getline(std::cin, blah);
    for(size_t i = 0; i < h; ++i) {
        std::string in;
        std::getline(std::cin, in);
        for(size_t j = 1; j < w+1; ++j) {
            map[j-1][i] = in[j];
        }
        // std::cout << std::endl;
    }

    std::getline(std::cin, blah);
    int types[1000];
    for(size_t i = 0; i < b; ++i) {
        char t;
        int s;
        std::cin >> t >> s;
        types[t] = s;
        // std::cout << t << " " << s << std::endl;
    }

    for(size_t i = 0; i < w; i += 2) {
        // std::cout << map[i][h-1] << std::endl;
        score[i][h-1] = types[map[i][h-1]];
        // std::cout << score[i][h-1] << std::endl;
    }
    for(size_t i = 1; i < w; i += 2) {
        // std::cout << map[i][h-1] << std::endl;
        score[i][h-1] = (score[i-1][h-1] + score[i+1][h-1])/2;
        // std::cout << score[i][h-1] << std::endl;
    }
    for(int j = h-2; j >= 0; --j) {
        for(int i = 0; i < w; ++i) {
            if(map[i][j] == ' ')
                score[i][j] = score[i][j+1];
            else {
                if(i == 0) score[i][j] = score[i+1][j+1];
                else if(i == w-1) score[i][j] = score[i-1][j+1];
                else { 
                    // std::cout << "Aveging (" << i << " " << j << " " << score[i-1][j+1] << " " << score[i+1][j+1] << std::endl;
                    score[i][j] = (score[i-1][j+1] + score[i+1][j+1]) / 2.0;
                }
            }
                
            // std::cout << i << " " << j << " score " << score[i][j] << std::endl;
        }
    }

    // std::cout << w << std::endl;
    // for(int i = 0; i < h; ++i) {
    //     for(int j = 0; j < w; ++j) {
    //         std::cout << score[j][i] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    double total = 0;
    for(size_t i = 0; i < n; ++i) {
        int pos; std::cin >> pos;
        total += score[pos-1][0];
    }
    std::cout.precision(17);
    std::cout << total << std::endl;
    return 0;

}
