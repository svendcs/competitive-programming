#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

struct Road {
	Road(int zombies, int to) : zombies(zombies), to(to) {}
	int zombies;
	int to;
};

bool operator<(const Road &a, const Road &b) {
	return a.zombies > b.zombies;
}

struct Camp {
	std::vector<Road> roads;
	bool supplies;
	int ammo;
};

int solve() {
	int camp_n, road_n;
	std::cin >> camp_n >> road_n;
	std::map<std::string,int> map;

	int via = -1;
	std::vector<Camp> camps;
	for(int i = 0; i < camp_n; ++i) {
		std::string name;
		int ammo;
		std::string supplies;

		std::cin >> name >> ammo >> supplies;
		map[name] = camps.size();

		Camp camp;
		camp.supplies = (supplies == "yes");
		camp.ammo = ammo;
		camps.push_back(camp);

		if(ammo > 0 && i != 0)
			via = i;
	}

	for(int i = 0; i < road_n; ++i) {
		std::string from, to;
		int zombies;
		std::cin >> from >> to >> zombies;
		int from_i = map[from];
		int to_i = map[to];

		camps[from_i].roads.push_back(Road(zombies, to_i));
		camps[to_i].roads.push_back(Road(zombies, from_i));
	}

	if(camps[0].supplies) // no walking required
		return 0;

	// try directly
	int via_required = -1;
	int direct_required = -1;
	bool visited[camp_n]; std::fill(visited, visited+camp_n, false);
	std::priority_queue<Road> queue;
	queue.push(Road(0, 0));

	while(!queue.empty()) {
		Road el = queue.top(); queue.pop();
		visited[el.to] = true;
		if(camps[el.to].supplies && direct_required == -1)
			direct_required = el.zombies;
		if(el.to == via)
			via_required = el.zombies;

		for(Road i : camps[el.to].roads) {
			if(visited[i.to]) continue;
			queue.push(Road(i.zombies + el.zombies, i.to));
		}
	}

	int via_via_required = -1;
	if(via_required != -1 && via_required <= camps[0].ammo) {
		std::fill(visited,visited+camp_n,false);

		while(queue.size() > 0) queue.pop();
		queue.push(Road(via_required, via));
		while(!queue.empty()) {
			Road el = queue.top(); queue.pop();
			visited[el.to] = true;
			if(camps[el.to].supplies && via_via_required == -1) {
				via_via_required = el.zombies;
				break;
			}

			for(Road i : camps[el.to].roads) {
				if(visited[i.to]) continue;
				queue.push(Road(i.zombies + el.zombies, i.to));
			}
		}
	}

	bool direct_possible = (direct_required != -1 && direct_required <= camps[0].ammo);
	bool via_possible = (via_via_required != -1 && via_via_required <= camps[0].ammo + camps[via].ammo);

	if(direct_possible && via_possible)
		return std::min(direct_required, via_via_required);
	if(direct_possible)
		return direct_required;
	if(via_possible)
		return via_via_required;
	return -1;
}

int main() {
	int n; std::cin >> n;
	for(int i = 0; i < n; ++i) {
		int r = solve();
		if(r == -1)
			std::cout << "No safe path" << std::endl;
		else
			std::cout << r << std::endl;
	}
	return 0;
}
