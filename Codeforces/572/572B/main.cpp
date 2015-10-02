#include <iostream>
#include <map>

int main() {
    std::map<int, int> sell_orders, buy_orders;

    int n, s;
    std::cin >> n >> s;
    for(int i = 0; i < n; ++i) {
        char dir;
        int p, q;
        std::cin >> dir >> p >> q;

        if(dir == 'B') {
            if(buy_orders.find(-p) == buy_orders.end())
                buy_orders.insert(std::make_pair(-p, q));
            else
                buy_orders[-p] += q;
        }
        else {
            if(sell_orders.find(p) == sell_orders.end())
                sell_orders.insert(std::make_pair(p, q));
            else
                sell_orders[p] += q;
        }
    }
    
    {
    auto i = sell_orders.begin();
    int j = 0;
    for(; j < s && i != sell_orders.end(); ++i, ++j) {
        std::cout << "S " << i->first << " " << i->second << std::endl;
    }
    }


    {
    auto i = buy_orders.begin();
    int j = 0;
    for(; j < s && i != buy_orders.end(); ++i, ++j) {
        std::cout << "B " << -(i->first) << " " << i->second << std::endl;
    }
    }

    
    return 0;
}
