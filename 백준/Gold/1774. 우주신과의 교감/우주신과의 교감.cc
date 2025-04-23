#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct node{
	int s;
	int e;
	double dist;
};

int n, m;
vector<int> root;
vector<pair<int, int>> coor; 
vector<node> edge;

int find(int x){
	if (root[x] == x)
		return x;
	return root[x] = find(root[x]);
}

void join(int a, int b){

	int x = find(a);
	int y = find(b);

	if (x < y)
		root[y] = x;
	else
		root[x] = y; 
}

bool com (node a, node b){
	return a.dist < b.dist;
}

int main() {

	cin >> n >> m;
	root.resize(n+1);
	coor.resize(n);

	for (int i = 1; i <= n; i++){
		root[i] = i;
	}

	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;

		coor[i] = {a, b};
	}

	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){

			double dx = coor[i].first - coor[j].first;
			double dy = coor[i].second - coor[j].second;
			double dist = sqrt(pow(dx, 2) + pow(dy, 2));

			edge.push_back({i+1, j+1, dist});
		}
	}

	sort(edge.begin(), edge.end(), com);

	for (int i = 0; i < m; i++){
		int a, b;

		cin >> a >> b;
		join(a, b);
	}

	double sum = 0;

	for (node v:edge){
		if (find(v.s) == find(v.e))
			continue;
		
		join(v.s, v.e);
		sum += v.dist;
	}

	printf("%0.2f", sum);


	return 0;
}