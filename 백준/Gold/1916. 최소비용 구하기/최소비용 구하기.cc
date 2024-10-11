#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector <pair<int, int> >> graph(n+1);
    vector<int> dist(n+1);

    for(int i = 0; i < m; i++){
        int a,b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b,c});
    }

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    priority_queue<pair<int, int>> pq;
    int s, e;
    cin >> s >> e;

    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()){
        int cost = -pq.top().first; 
        int node = pq.top().second;

        pq.pop();

        if (cost > dist[node]) 
            continue;

        for (int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i].first;
            int ncost = graph[node][i].second;

            if (dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }

    cout << dist[e];
}

