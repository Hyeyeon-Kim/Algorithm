#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

long long dist[510];
int n, m;
vector <pair<pair<int, int>, int>> edge;

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		edge.push_back({ {a,b},c });
	}

	dist[1] = 0;

	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < edge.size(); j++)
		{
			int from = edge[j].first.first;
			int to = edge[j].first.second;
			int cost = edge[j].second;

			if (dist[from] == INF)
				continue;

			if (dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}
	
	for (int i = 0; i < edge.size(); i++)
	{
		int from = edge[i].first.first;
		int to = edge[i].first.second;
		int cost = edge[i].second;

		if (dist[from] == INF)
			continue;

		if (dist[to] > dist[from] + cost)
		{
			cout << -1;
			return 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (dist[i] == INF)
			cout << -1 << "\n";
		else
			cout << dist[i] << "\n";
	}
}