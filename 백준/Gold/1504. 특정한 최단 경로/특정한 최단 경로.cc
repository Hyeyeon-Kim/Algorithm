#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static const int INF = 2147483647;

int n, e;
vector<pair<int,int>> edge[801];

// 다익스트라 함수: start에서 모든 정점까지의 최단거리를 구해서 리턴
vector<int> dijkstra(int start) {
    vector<int> dist(n+1, INF);
    dist[start] = 0;
    
    // 최소 힙 (cost가 작은 순서대로)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        
        // 이미 더 짧은 경로로 방문했다면 스킵
        if (dist[current_node] < current_cost) continue;
        
        // 인접 정점 순회
        for (auto &adj : edge[current_node]) {
            int next_node = adj.first;
            int weight = adj.second;
            
            // 다음 정점까지의 비용이 더 작으면 갱신
            if (dist[next_node] > current_cost + weight) {
                dist[next_node] = current_cost + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> e;
    
    for (int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        // 양방향 그래프
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    // 1. 1번에서 모든 정점까지의 최단거리
    vector<int> dist1 = dijkstra(1);

    // 2. v1에서 모든 정점까지의 최단거리
    vector<int> distV1 = dijkstra(v1);

    // 3. v2에서 모든 정점까지의 최단거리
    vector<int> distV2 = dijkstra(v2);

    // 경로 1: 1 -> v1 -> v2 -> n
    // dist1[v1], distV1[v2], distV2[n] 순으로 합산
    long long path1 = (long long)dist1[v1] + distV1[v2] + distV2[n];

    // 경로 2: 1 -> v2 -> v1 -> n
    // dist1[v2], distV2[v1], distV1[n] 순으로 합산
    long long path2 = (long long)dist1[v2] + distV2[v1] + distV1[n];

    long long ans = min(path1, path2);

    // 두 경로 모두 INF 이상이라면 갈 수 없는 경우이므로 -1 출력
    if (ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
