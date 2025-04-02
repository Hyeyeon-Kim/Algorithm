#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int> > board;
vector<vector<int> > check;
int ans = 0;  
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int capture_dfs(int i, int j, bool &captured, vector<vector<bool> > &visited) {
    visited[i][j] = true;
    int count = 1;
    for (int d = 0; d < 4; d++){
        int ni = i + dir[d][0];
        int nj = j + dir[d][1];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if (check[ni][nj] == 0) {
            captured = false;
        }
        if (check[ni][nj] == 2 && !visited[ni][nj]) {
            count += capture_dfs(ni, nj, captured, visited);
        }
    }
    return count;
}

void dfs() {
    int capturedCount = 0;
    vector<vector<bool> > visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (check[i][j] == 2 && !visited[i][j]) {
                bool captured = true;
                int cnt = capture_dfs(i, j, captured, visited);
                if (captured) {
                    capturedCount += cnt;
                }
            }
        }
    }
    ans = max(ans, capturedCount);
}

void choice() {
    vector<pair<int, int> > empties;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == 0) {
                empties.push_back(make_pair(i, j));
            }
        }
    }
    int sz = empties.size();

    for (int a = 0; a < sz; a++){
        for (int b = a + 1; b < sz; b++){

            check = board;
            int ax = empties[a].first, ay = empties[a].second;
            int bx = empties[b].first, by = empties[b].second;

            check[ax][ay] = 1;
            check[bx][by] = 1;

            dfs();
        }
    }
}


int main() {
	cin >> n >> m;
	board = vector<vector<int> >(n, vector<int>(m));

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}

	choice();

	cout << ans;
	return 0;
}