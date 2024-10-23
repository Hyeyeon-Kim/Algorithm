#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> edge;
vector<int> Info;
vector<int> visit;

int ans  = 0;

void dfs(int sheep , int wolf){
    if (sheep > ans)
        ans = sheep;
    
    if (sheep > wolf){
        for (int i = 0; i < visit.size(); i++){
            if (visit[i]){
                visit[i] = 0;
                for (int j = 0 ; j < edge[i].size(); j++)
                    visit[edge[i][j]] = 1;

                dfs(sheep + (Info[i] ^ 1), wolf + Info[i]);

                for (int j = 0 ; j < edge[i].size(); j++)
                    visit[edge[i][j]] = 0;
                visit[i] = 1;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    edge.resize(info.size());
    visit.resize(info.size(), 0);
    Info = info;
    
    for (int i = 0; i < edges.size(); i++)
        edge[edges[i][0]].push_back(edges[i][1]);
    
    for (int i = 0 ; i < edge[0].size(); i++)
        visit[edge[0][i]] = 1;
    dfs(1, 0);
    
    return ans;
}