#include <iostream>
#include <deque>
#include <set>

int calculate_state(const std::deque<int> & a, const std::deque<int> & b) {
    long long state = a.size();
    for(auto i : a) {
        state *= 10;
        state += i;
    }
    for(auto i : b) {
        state *= 10;
        state += i;
    }
    return state;
}

int main() {
    int n; std::cin >> n;
    std::set<long long> seen;

    
    std::deque<int> a; int c_a;
    std::deque<int> b; int c_b;

    std::cin >> c_a;
    for(int i = 0; i < c_a; ++i) {
        int tmp; std::cin >> tmp;
        a.push_back(tmp);
    }
    std::cin >> c_b;
    for(int i = 0; i < c_b; ++i) {
        int tmp; std::cin >> tmp;
        b.push_back(tmp);
    }

    int i = 0; 
    long long state = calculate_state(a, b);
    while(!a.empty() && !b.empty() && seen.count(state) == 0) {
        seen.insert(state);
        int topa = a.front(); a.pop_front(); 
        int topb = b.front(); b.pop_front();

        if(topa > topb) {
            a.push_back(topb);
            a.push_back(topa);
        }
        else {
            b.push_back(topa);
            b.push_back(topb);
        }
        ++i;
        state = calculate_state(a, b);
    }

    if(a.empty()) { // b wins
        std::cout << i << " " << 2 << std::endl;
    }
    else if(b.empty()) { // a wind
        std::cout << i << " " << 1 << std::endl;
    }
    else
        std::cout << "-1" << std::endl;
}
