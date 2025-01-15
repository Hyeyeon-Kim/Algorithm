#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edge[n+1];

	for (int i = 0; i < m; i++){
		int a, b, c;

		cin >> a >> b >> c;

		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}

	vector <int> dist(n+1);
	vector <int> pre_node(n+1);

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	priority_queue<pair<int, int>> pq;
	pq.push({0, 1});
	dist[1] = 0;

	while (!pq.empty()){
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (cost > dist[node])
			continue;
		
		for (int i = 0 ;i < edge[node].size(); i++){
			int next = edge[node][i].first;
			int next_cost = edge[node][i].second;

			if (dist[next] > dist[node] + next_cost){
				dist[next] = dist[node] + next_cost;
				pre_node[next] = node;
				pq.push({-dist[next], next});
			}
		}	
	}

	printf("%d\n", n-1);

	for (int i = 2; i <= n; i++){
		printf("%d %d\n", i, pre_node[i]);
	}
}