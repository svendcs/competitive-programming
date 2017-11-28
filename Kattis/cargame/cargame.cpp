#include <vector>
#include <iostream>
#include <cmath>

#define clamp(x, lo, hi) std::min(hi, std::max(lo, x))
#define rep(i, a, b) for(int i = a; i < (b); ++i)

struct Node {
    Node() {
        word = -1;
        rep(i,0,26) children[i] = nullptr;
    }

    int word;
    Node * children[26];

    Node * get_child(char c) {
        if (this->children[c-'a'] == nullptr)
            this->children[c-'a'] = new Node;
        return this->children[c-'a'];
    }
};

int main() {
    int n, m; std::cin >> n >> m;

    std::vector<std::string> words(n);
    Node * root = new Node;
    for(size_t i = 0; i < n; ++i) {
        std::cin >> words[i];
        std::string word = words[i];

        rep(x, 0, word.size()) {
            Node * a = root->get_child(word[x]);
            rep(y,x+1,word.size()) {
                Node * b = a->get_child(word[y]);
                rep(z,y+1,word.size()) {
                    Node * c = b->get_child(word[z]);
                    
                    if (c->word == -1)
                        c->word = i;
                }
            }
        }
    }

    for(size_t i = 0; i < m; ++i) {
        std::string plate;
        std::cin >> plate;
        rep(j,0,3)
            plate[j] = plate[j]-'A'+'a';
        // std::cout << plate << std::endl;

        Node * node = root;
        rep(j,0,3) {
            node = node->get_child(plate[j]);
        }

        std::cout << (node->word == -1 ? "No valid word" : words[node->word])<< std::endl;
    }

    return 0;
}
