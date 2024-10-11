#include <iostream>
#include <queue>
#include <vector>
#define MAX 20010
#define INF 987654321
using namespace std;

int v, e;
int start = 0;
int dist[MAX];

vector <pair<int, int> > graph[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e >> start;

	for (int i = 1; i <= e; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		graph[a].push_back(make_pair(b,c));
	}
	
	for (int j = 1; j <= v; j++)
		dist[j] = INF;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (pq.empty() == 0)
	{
		int cost = -pq.top().first;
		int nod = pq.top().second;
		pq.pop();
        
        if (cost > dist[nod]) 
            continue;

		for (int i = 0; i < graph[nod].size(); i++)
		{
			int next = graph[nod][i].first;
			int next_cost = graph[nod][i].second;

			if (dist[next] > cost + next_cost)
			{
				dist[next] = cost + next_cost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}
