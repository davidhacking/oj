#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

/*

input:
1 4
10000 3 2
2 8000
3 5000
1000 2 1
4 200
3000 2 1
4 200
50 2 0
*/

int delta_level, total;

struct Goods {
	int v;
	int money;
	int level;
	int edge_num;
};

Goods goods[1250];
int goods_index;

struct Edge {
	int a;
	int b;
	int money;
};

Edge edge[10240];
int edge_index;

// vector<int> path[1024];
// int path_index = 0;

struct Target {
	int end_pointer;
	int deep;
	vector<int> parent_chain;
};

vector<Target> targets;

void print_path(vector<int> path) {
	for (int j = path.size() - 1; j >= 0; j--) {
		printf("%d, ", path[j]);
	}
	printf("\n");
}

int compute_sum(vector<int> path) {
	// print_path(path);
	int tmp_sum = 0;
	for (int j = path.size() - 1; j >= 0; j--) {
		// if (j == path.size() - 1) {
		// 	tmp_sum += goods[path[j]].money;
		// }
		if (j != 0) {
			for (int k = 0; k < edge_index; k++) {
				if (edge[k].a == path[j] && edge[k].b == path[j - 1]) {
					tmp_sum += edge[k].money;
				}
			}
		}
	}
	return tmp_sum;
}

bool can_change(vector<int> path) {
	for (int i = 0; i < path.size(); i++) //枚举
	{
		for (int j = 0; j < path.size() && i != j; j++)
		{	
			if (abs(goods[path[i]].level - goods[path[j]].level) > delta_level) {
				return false;
			}
		}
	}
	return true;
}

int compute_min_money() {
	// find path
	int source = 1;
	Target target;
	target.end_pointer = source;
	target.deep = 1;
	target.parent_chain.push_back(target.end_pointer);
	targets.push_back(target);
	bool flag = false;
	int deep = 0;
	int sum = goods[source].money;
	while (true) {
		flag = false;
		if (deep > (goods_index + 1)) {
			break;
		}
		// printf("deep: %d\n", deep);
		deep++;
		int targets_size = targets.size();
		vector<Target> tmp_targets;
		tmp_targets.assign(targets.begin(), targets.end());
		targets.clear();
		for (int i = 0; i < edge_index; i++) {
			// printf("targets_size: %d\n", targets_size);
			for (int j = 0; j < targets_size; j++) {
				// printf("path_index: %d\n", path_index);
				if (tmp_targets[j].deep != deep) {
					continue;
				}
				// printf("b_level: %d, a_level: %d, delta_level: %d\n", edge[i].b, edge[i].a, (goods[edge[i].b].level - goods[edge[i].a].level));
				int tmp_delta_level = goods[edge[i].b].level - goods[edge[i].a].level;
				if (abs(tmp_delta_level) > delta_level) {
					continue;
				}
				if (edge[i].b == tmp_targets[j].end_pointer) {
					bool find_ring = false;
					for (int k = 0; k < tmp_targets[j].parent_chain.size(); k++) {
						if (tmp_targets[j].parent_chain[k] == edge[i].a) {
							find_ring = true;
						}
					}
					if (find_ring) {
						continue;
					}
					vector<int> path;
					path.assign(tmp_targets[j].parent_chain.begin(), tmp_targets[j].parent_chain.end());
					path.push_back(edge[i].a);
					if (can_change(path) == false) {
						continue;
					}
					int tmp_sum = compute_sum(path);
					// 这个判断十分重要可以降低非常多的复杂度
					if (sum < tmp_sum) {
						continue;
					}
					tmp_sum += goods[path[path.size() - 1]].money;
					if (sum > tmp_sum) {
						sum = tmp_sum;
					}
					target.end_pointer = edge[i].a;
					target.deep = deep + 1;
					target.parent_chain.assign(path.begin(), path.end());
					targets.push_back(target);
					flag = true;
				}
			}
		}
		if (!flag) {
			break;
		}
	}
	// print_path();
	// int sum = goods[source].money;
	// for (int i = 0; i < path_index; i++) {
	// 	int tmp_sum = compute_sum(path[i]);
	// 	if (sum > tmp_sum) {
	// 		sum = tmp_sum;
	// 	}
	// }
	return sum;
}

int main() {
	// freopen("/Users/david/myFile/OJ/poj1062/test.data", "r", stdin);
	while(true) {
		goods_index = 0;
		edge_index = 0;
		// path_index = 0;
		// for (int i = 0; i < 1024; i++) {
		// 	path[i].clear();
		// }
		targets.clear();
		if (scanf("%d %d", &delta_level, &total) == EOF) {
			return 0;
		}
		for (int i = 1; i <= total; i++) {
			goods_index = i;
			goods[goods_index].v = goods_index;
			scanf("%d %d %d", &goods[goods_index].money, &goods[goods_index].level, &goods[goods_index].edge_num);
			for (int j = 0; j < goods[goods_index].edge_num; j++) {
				scanf("%d %d", &edge[edge_index].a, &edge[edge_index].money);
				edge[edge_index].b = goods[goods_index].v;
				edge_index++;
			}
		}
		cout << compute_min_money() << endl;
	}
	return 0;
}