#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> gragh(n+1);
    vector<int> ingree(n+1);
    vector<int> time(n+1);
    vector<int> spendtime(n+1);
    queue<int> q;

    for (int i = 1; i <= n; i++){
        cin >> time[i];
        cin >> ingree[i];

        if (ingree[i] == 0){
            q.push(i);
            spendtime[i] = time[i];
        }

        for (int j = 0; j < ingree[i]; j++){
            int node;
            cin >> node;
            gragh[node].push_back(i);
        }
    }
    
    while(!q.empty()){
        // int pretime = q.front().first;
        int node = q.front();
        // ans = max(ans, pretime+time[node]);
        q.pop();

        for (int i = 0; i < gragh[node].size(); i++){
            int next = gragh[node][i];
            ingree[next]--;
            spendtime[next] = max(spendtime[next], spendtime[node] + time[next]);
            if (ingree[next] == 0)
                q.push(next);
        }
    }
    int ans = *max_element(spendtime.begin(), spendtime.end());
    cout << ans;
}   
