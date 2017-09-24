#include <iostream>
#include <vector>

std::vector<int> elements;
size_t n;
void print() {
    for(size_t i = 0; i < n; ++i) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

size_t solve(size_t begin, size_t end) {
    // std::cout << begin << " " << end << std::endl;
    if (end-begin <= 1)
        return 0;

    size_t mid = (begin + end) / 2;
    size_t inversions = 0;
    inversions += solve(begin, mid);
    inversions += solve(mid, end);

    size_t i = begin;
    size_t j = mid;

    std::vector<int> yolo;
    while(i < mid && j < end) {
        if (elements[i] > elements[j]) {
            yolo.push_back(elements[j]);
            ++j;
            inversions += mid - i;
        }
        else {
            yolo.push_back(elements[i]);
            ++i;
        }
    }
    while(i < mid) {
        yolo.push_back(elements[i]);
        ++i;
    }
    while(j < end) {
        yolo.push_back(elements[j]);
        ++j;
    }

    for(size_t i = begin; i != end; ++i) {
        elements[i] = yolo[i-begin];
    }
    return inversions;
}

int main() {
    std::cin >> n;

    for(size_t i = 0; i < n; ++i) {
        int a; std::cin >>a;
        elements.push_back(a);
    }
    // print();

    std::cout << solve(0, n) << std::endl;
    // print();
    return 0;
}
