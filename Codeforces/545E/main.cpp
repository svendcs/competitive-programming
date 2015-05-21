#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

// dijkstra, but take smallest edges first
// careful with overflow

struct edge {
    size_t weight, index, to;
    unsigned long long cumm_weight;

    edge(size_t weight, size_t index, size_t to)
    : weight(weight), index(index), to(to)
    {
    }
};

bool operator<(const edge & a, const edge & b) {
    // inverted because c++ is stupid
    if(a.cumm_weight != b.cumm_weight)
        return a.cumm_weight > b.cumm_weight;
    return a.weight > b.weight;
}

struct vertex {
    std::vector<edge> edges;
    bool visited;

    vertex() : visited(false) {}
};

int main() {
    size_t n, m; // vertices, edges
    std::cin >> n >> m;

    std::vector<vertex> vertices(n);
    for(size_t i = 0; i < m; ++i) {
        size_t from, to, weight, index;

        index = i+1;
        std::cin >> from >> to >> weight;
        --from; --to;

        vertices[from].edges.push_back(edge(weight, index, to));
        vertices[to].edges.push_back(edge(weight, index, from));
    }

    size_t begin;
    std::cin >> begin;
    --begin;

    std::vector<size_t> result;

    std::priority_queue<edge> queue; // cumm. length, index

    for(edge e : vertices[begin].edges) {
        e.cumm_weight = e.weight; 
        queue.push(e);
    }

    vertices[begin].visited = true;
    unsigned long long total_weight = 0; 

    while(!queue.empty()) {
        edge item = queue.top();
        queue.pop();

        //std::cout << "Taking edge " << item.index << " cumm_weight is " << item.cumm_weight << std::endl;
        
        if(vertices[item.to].visited)
            continue;

        vertices[item.to].visited = true;
        result.push_back(item.index);
        total_weight += item.weight;
        for(edge e : vertices[item.to].edges) {
            if(vertices[e.to].visited) continue;
            e.cumm_weight  = item.cumm_weight + e.weight;
            queue.push(e);
        }
    }

    std::cout << total_weight << std::endl;
    for(auto i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
