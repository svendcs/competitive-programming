#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

int main() {
    size_t w, h;
    std::cin >> w >> h;
    size_t whole = 0;
    size_t half = 0;
    for(size_t i = 0; i < h; ++i) {
        if(i % 2 == 1) {
            if(w % 2 == 0) {
                half += 2;
                whole += (w-2) / 2;
            }
            else {
               half += 1;
               whole += (w-1) / 2;
            }
        }
        else {
            if(w % 2 == 1)
                half++;
            whole += w / 2;
        }
    }

    std::cout << whole << " " << half << std::endl;
    return 0;

}
