#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<vector<int>> edges;
vector<int> dist;
int max_ = 0;

void bfs(){
    priority_queue<pair<int,int>> q;
    q.push({0, 1});
    dist[1] = 0;
    
    while (!q.empty()){
        int cnt = -q.top().first;
        int node = q.top().second;
        
        q.pop();
    
        if (dist[node] < cnt)
            continue;
        
        for (int num: edges[node]){
            if (dist[num] > cnt + 1){
                dist[num] = cnt+1;
                q.push({-(cnt + 1), num});
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    edges.resize(n+1);
    dist.resize(n+1);
    
    for (int j = 1; j <= n; j++)
		dist[j] = INF;
    
    for (vector v: edge){
        int a = v[0];
        int b = v[1];
        
        edges[a].push_back(b);
        edges[b].push_back(a); 
    }
    
    bfs();
    
    int answer = 0;
    
    int max_ = 0;
    
    for (int i = 1; i <= n; i++)
        max_ = max(dist[i], max_);

    for (int i = 1; i <= n; i++)
        if (dist[i] == max_)
            answer++;
    
    return answer;
}