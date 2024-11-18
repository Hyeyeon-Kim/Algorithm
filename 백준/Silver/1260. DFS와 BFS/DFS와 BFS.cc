#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int adjacent[MAX+2][MAX+2] = {0};
int visited[MAX+2] = {0};
int n, m, v;

void dfs(int v) {
	cout << v << " ";
	visited[v] = 1;
	for (int i=1; i<=n; i++) {
		if(adjacent[v][i] && !visited[i]) dfs(i);
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = 0;
	while (!q.empty()) {
		int v  = q.front();
		q.pop();
		cout << v << " ";
		for (int i=1; i<=n; i++) {
			if(adjacent[v][i] && visited[i]) {
				q.push(i);
				visited[i] = 0;
			}
		}
	}
	cout << "\n";
}

int main(int argc, const char * argv[]) {
	cin >> n >> m >> v;
	for (int i=0; i<m; i++) {
		int x, y; cin >> x >> y;
		adjacent[x][y] = 1;
		adjacent[y][x] = 1;
	}
	dfs(v);
	cout << "\n";
	bfs(v);
	return 0;
}