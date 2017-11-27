#include <algorithm>
#include <utility>
#include <iostream>

struct Node {
    Node() {
        std::fill(children, children+26, nullptr);
        count = 0;
    }

    Node* children[26];
    int count;
};

int main() {
    int n; std::cin >> n;
    Node * root = new Node;

    for (size_t i = 0; i < n; ++i) {
        std::string word; std::cin >> word;
        Node * node = root;
        for (char c : word) {
            if (node->children[c-'a'] == nullptr)
                node->children[c-'a'] = new Node;

            node = node->children[c-'a'];
            node->count++;
        }

        std::cout << node->count - 1 << std::endl;
    }
}
