#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int x;
	int y;
	int cnt;
};

int main() {
	int n, m;

	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	vector<vector<int>> visited(n, vector<int>(m));

	queue <node> q;

	for (int i = 0; i < n ; i ++){
		string s;

		cin >> s;

		for (int j = 0; j < m; j++){
			v[i][j] = s[j] - '0';

			if (v[i][j] == 2){
				visited[i][j] = 1;
				q.push({i, j, 0});
			}
		}
	}

	int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
	int ans = -1;

	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		if (v[x][y] >= 3){
			ans = cnt;
			break;
		}

		for (int i = 0; i < 4; i++){
			int nx = dir[i][0] + x;
			int ny = dir[i][1] + y;
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (v[nx][ny] == 1)
				continue;
			if (visited[nx][ny])
				continue;
			visited[nx][ny] = 1;
			q.push({nx,ny,cnt+1});
		}
	}

	if (ans == -1)
		cout << "NIE";
	else
		cout << "TAK\n" << ans; 

	return 0;
}