/*
bellman-ford algo
http://www.wutianqi.com/?p=1912
BELLMAN-FORD(G, w, s)
INITIALIZE-SINGLE-SOURCE(G, s)
for i ← 1 to |V[G]| - 1
  do for each edge (u, v) ∈ E[G]
         do RELAX(u, v, w)
for each edge (u, v) ∈ E[G]
  do if d[v] > d[u] + w(u, v)
        then return FALSE
return TRUE

relax: 
d（v） > d (u) + w(u,v)

test:
3 2 1 20.0
1 2 1.00 1.00 1.00 1.00
2 3 1.10 1.00 1.10 1.00
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

#define VERTEX_NUM 200

int currency_number, exchange_number, source;
double origin_money = 0;
double max_double = 0;

struct Edge {
	int v_a;
	int v_b;
	double rate;
	double commission;
};

Edge edges[10005];
int edges_index = 0;
double distance2v[VERTEX_NUM];

double exchange_func(double money, double rate, double commission) {
	return (money - commission) * rate;
}

void compute_relax() {
	distance2v[source] = 0.0f;
	for (int i = 1; i <= currency_number; i++) {
		for (int j = 0; j < edges_index; j++) {
			if (memcmp(&distance2v[i], &max_double, sizeof(double)) == 0) {
				if (edges[j].v_a == source && edges[j].v_b == i) {
					distance2v[edges[j].v_b] = exchange_func(origin_money, edges[j].rate, edges[j].commission);
				}
			} 
			if (i == edges[j].v_b && memcmp(&distance2v[edges[j].v_a], &max_double, sizeof(double)) != 0) {
				if (memcmp(&distance2v[edges[j].v_b], &max_double, sizeof(double)) == 0) {
					distance2v[edges[j].v_b] = exchange_func(distance2v[edges[j].v_a], edges[j].rate, edges[j].commission);
				} else if (distance2v[edges[j].v_b] < exchange_func(distance2v[edges[j].v_a], edges[j].rate, edges[j].commission)) {
					distance2v[edges[j].v_b] = exchange_func(distance2v[edges[j].v_a], edges[j].rate, edges[j].commission);
				}
			}
		}
	}
}

int main() {
	freopen("/Users/david/myFile/OJ/poj1860/test.data", "r", stdin);
	memset(&max_double, 0xff, sizeof(double));
	while (true) {
		edges_index = 0;
		if (scanf("%d %d %d %lf", &currency_number, &exchange_number, &source, &origin_money) == EOF) {
			return 0;
		}
		for (int i = 0; i < exchange_number; i++) {
			int a, b;
			double r_ab, c_ab, r_ba, c_ba;
			if (scanf("%d %d %lf %lf %lf %lf", &a, &b, &r_ab, &c_ab, &r_ba, &c_ba) == EOF) {
				return 0;
			}
			edges[edges_index].v_a = a;
			edges[edges_index].v_b = b;
			edges[edges_index].rate = r_ab;
			edges[edges_index].commission = c_ab;
			edges_index++;
			edges[edges_index].v_a = b;
			edges[edges_index].v_b = a;
			edges[edges_index].rate = r_ba;
			edges[edges_index].commission = c_ba;
			edges_index++;
		}
		// reset distance
		memset(distance2v, 0xff, VERTEX_NUM * sizeof(double));
		compute_relax();
		// 
	}
	return 0;
}

