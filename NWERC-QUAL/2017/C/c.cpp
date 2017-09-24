#include <iostream>
#include <map>

int main() {
    int q, n;
    std::cin >> n >> q;

    std::map<int, int> buckets;
    for(size_t i = 0; i < n; ++i) {
        int bucket, volume; std::cin >> bucket >> volume;

        if(buckets.find(bucket) == buckets.end())
            buckets[bucket] = volume;
        else
            buckets[bucket] += volume;
    }

    for(size_t i = 0; i < q; ++i) {
        int color, volume;
        std::cin >> color >> volume;

        int sum = 0;
        auto begin = buckets.lower_bound(color-1000);
        auto end = buckets.upper_bound(color+1000);
        for(auto i = begin; i != end; ++i) {
            sum += i->second;
            if (sum >= volume) break;
        }

        if (sum >= volume)
            std::cout << "yes" << std::endl;
        else
            std::cout << "no" << std::endl;
    }


    return 0;
}
