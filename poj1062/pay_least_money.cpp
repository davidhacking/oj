#include <string.h>
#include <iostream>
#include <stdio.h>

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

Goods goods[125];
int goods_index;

struct Edge {
	int a;
	int b;
	int money;
};

Edge edge[1024];
int edge_index;

int compute_min_money() {

}

int main() {
	while(true) {
		goods_index = 0;
		edge_index = 0;
		if (scanf("%d %d", &delta_level, &total) == EOF) {
			return 0;
		}
		for (int i = 0; i < total; i++) {
			goods[goods_index].v = i + 1;
			scanf("%d %d %d", &goods[goods_index].money, &goods[goods_index].level, &goods[goods_index].edge_num);
			edge[edge_index].a = goods[goods_index].v;
			edge[edge_index].b = goods[goods_index].v;
			edge[edge_index].money = goods[goods_index].money;
			edge_index++;
			for (int j = 0; j < goods[goods_index].edge_num; j++) {
				scanf("%d %d", &edge[edge_index].a, &edge[edge_index].money);
				edge[edge_index].b = goods[goods_index].v;
				edge_index++;
			}
			goods_index++;
		}
		cout << compute_min_money() << endl;
	}
	return 0;
}