#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<vector<int> > map;
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
int visited[1000][1000][11] = {0};

struct node{
	int x;
	int y;
	int cnt;
	int cost;
};

int main() {

	cin >> n >> m >> k;
	map = vector<vector<int> > (n, vector<int>(m, 0));

		
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}


	queue<node> q;
	node t = {0,0,0,1};
	visited[0][0][0] = 1;
	q.push(t);
	int ans = 2147483647;

	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int cost = q.front().cost;
		
		q.pop();

		if (x == n-1 && y == m-1){
			ans = min(ans, cost);
			break;
		}

		for (int i = 0; i < 4; i++){
			int nx = dir[i][0] + x;
			int ny = dir[i][1] + y;

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			
			if (map[nx][ny] == 0) {
                if (!visited[nx][ny][cnt]){
                    visited[nx][ny][cnt] = 1;
					node t = {nx, ny, cnt, cost+1};
                    q.push(t);
                }
            }

            else if (cnt < k) {
                if (!visited[nx][ny][cnt+1]){
                    visited[nx][ny][cnt+1] = 1;
					node t = {nx, ny, cnt+1, cost+1};
                    q.push(t);
                }
            }
		}
	}

	if (ans == 2147483647)
		cout << -1;
	else
		cout << ans;
	return 0;
}