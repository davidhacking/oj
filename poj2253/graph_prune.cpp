/*
pseudocode
1. get n vertex V[N]
2. generate edge E[N*(N-1)]
3. sort edge with edge length
4. prune the max length edge 
	[sub pseudocode whether edge can prune]
	if the vertex have no edge in E
		
	if can prune
		set prune_flag = true
	if can not prune 
		set cant_prune_flag = true
5. if all edge has been set prune_flag = true or cant_prune_flag = true
		prune finish
6. sort edge that cant_prune_flag == true 
7. return the max edge length

test:
2
0 0
3 4

3
17 4
19 4
18 5

0
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Vertex{
	int x;
	int y;
} vertex[256];
int vertex_len = 0;

struct Edge {
	double length;
	int a;
	int b;
	bool cant_prune_flag;
	bool prune_flag;
} edge[65280];
int edge_len = 0;

bool compare_edge(Edge a, Edge b) {
	if (a.prune_flag == true) {
		if (b.prune_flag == true) {
			return a.length > b.length;
		} else {
			return 0.0f > b.length;
		}
	} else {
		if (b.prune_flag == true) {
			return a.length > 0.0f;
		} else {
			return a.length > b.length;
		}
	}
}

bool compare_edge2(Edge a, Edge b) {
	if (a.prune_flag == true) {
		if (b.prune_flag == true) {
			return a.length < b.length;
		} else {
			return false;
		}
	} else {
		if (b.prune_flag == true) {
			return true;
		} else {
			return a.length < b.length;
		}
	}
}

void construct_edge() {
	edge_len = vertex_len * (vertex_len - 1) / 2;
	int tmp_index = 0;
	for (int i = 0; i < vertex_len; i++) {
		for (int j = i + 1; j < vertex_len && j != i; j++) {
			double x1 = (vertex[i].x - vertex[j].x) * (vertex[i].x - vertex[j].x);
			double x2 = (vertex[i].y - vertex[j].y) * (vertex[i].y - vertex[j].y);
			edge[tmp_index].length = sqrt(x1 + x2);
			edge[tmp_index].a = i;
			edge[tmp_index].b = j;
			edge[tmp_index].cant_prune_flag = false;
			edge[tmp_index].prune_flag = false;
			tmp_index++;
		}
	}
	sort(edge, edge + edge_len, compare_edge);
}

bool can_prune_this_edge(int edge_index) {
	if (edge[edge_index].cant_prune_flag) {
		return false;
	}
	int a, b;
	a = edge[edge_index].a;
	b = edge[edge_index].b;
	edge[edge_index].prune_flag = true;
	bool find_a = false;
	bool find_b = false;
	for (int i = 0; i < edge_len; i++) {
		if (edge[i].prune_flag == false) {
			if (edge[i].a == a || edge[i].b == a) {
				find_a = true;
				if (find_a && find_b) {
					edge[edge_index].prune_flag = false;
					return true;
				}
			}
			if (edge[i].a == b || edge[i].b == b) {
				find_b = true;
				if (find_a && find_b) {
					edge[edge_index].prune_flag = false;
					return true;
				}
			}
		}
	}
	edge[edge_index].prune_flag = false;
	return false;
}

void prune_max_edge() {
	for (int i = 0; i < edge_len; i++) {
		if (can_prune_this_edge(i)) {
			edge[i].prune_flag = true;
		} else {
			edge[i].cant_prune_flag = true;
		}
	}
}

int main() {
	freopen("/Users/david/myFile/OJ/poj2253/test.data", "r", stdin);
	int scenario = 1;
	while (true) {
		if (scanf("%d", &vertex_len) == EOF || vertex_len == 0) {
			return 0;
		}
		for (int i = 0; i < vertex_len; i++) {
			scanf("%d %d", &vertex[i].x, &vertex[i].y);
		}
		construct_edge();
		prune_max_edge();
		sort(edge, edge + edge_len, compare_edge);
		printf("Scenario #%d\n", scenario++);
		cout << fixed << setprecision(3);
		printf("Frog Distance = ");
		cout << edge[0].length << "\n\n";
	}
	return 0;
}