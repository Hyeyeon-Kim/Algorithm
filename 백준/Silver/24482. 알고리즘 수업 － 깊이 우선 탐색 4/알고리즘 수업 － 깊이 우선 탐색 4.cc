#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m, r;
vector<set<int, greater<int>>> edge;
vector<int> visited;

void dfs(int v, int d){
	visited[v] = d;
    
	for (int nx : edge[v]) {
        if (visited[nx] == -1) {
            dfs(nx, d+1);
        }
    }
}

int main() {

	cin >> n >> m >> r;
	edge.resize(n+1);
	visited = vector<int>(n+1, -1);

	for (int i = 0; i < m; i++){
		int a, b;

		cin >> a >> b;

		edge[a].insert(b);
		edge[b].insert(a);
	}

	dfs(r, 0);

	for (int i = 1; i <= n; i++){
		cout << visited[i] << "\n";
	}
	return 0;
}