#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

struct Employee {
    int id;
    int salary;
    int height;
    int boss;
    std::vector<int> subordinates;
    int rec_count;
    bool visited;

    bool operator<(const Employee & other) const {
        if (height != other.height) return height < other.height;

        return salary < other.salary;
    }
};

std::vector<Employee> employees;
int m, q;

int visit(size_t id) {
    if (employees[id].visited)
        return employees[id].rec_count;

    employees[id].rec_count = 0;
    employees[id].visited = true;

    for (int sub : employees[id].subordinates) {
        employees[id].rec_count += visit(sub) + 1;
    }

    return employees[id].rec_count;
}

int main() {
    std::cin >> m >> q;

    for (size_t i = 0; i < m; ++i) {
        Employee e;
        std::cin >> e.id >> e.salary >> e.height;
        e.visited = false;
        employees.push_back(e);
    }

    std::sort(employees.begin(), employees.end());

    std::map<int, int> temp;
    for (size_t i = 0; i < m; ++i) {
        size_t j = m-1-i;
        auto it = temp.lower_bound(employees[j].salary);
        if (it == temp.end())
            employees[j].boss = -1;
        else {
            employees[j].boss = it->second;
            employees[it->second].subordinates.push_back(j);
        }
        temp.insert(std::make_pair(employees[j].salary, j));
    }


    std::map<int, int> map;
    for (size_t i = 0; i < m; ++i) {
        map.insert(std::make_pair(employees[i].id, i));
        if (employees[i].visited)
            continue;
        visit(i);
    }

    // for(auto e : employees)
    //     std::cout << e.id << ", salary=" << e.salary << ", height=" << e.height << ", e.boss=" << e.boss << ", e.rec_count=" << e.rec_count << std::endl;

    for (size_t i = 0; i < q; ++i) {
        int a; std::cin >> a;
        int j = map[a];
        // std::cout << j << " " << a << std::endl;
        std::cout << (employees[j].boss == -1 ? 0 : employees[employees[j].boss].id) << " " << employees[j].rec_count << std::endl;
    }

    return 0;
}
