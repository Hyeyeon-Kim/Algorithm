#include <iostream>
#include <algorithm>
using namespace std;

char map[50][50] = { 0 };
char chess[8][8];

int solve()
{
	int cntWB = 0;
	int cntBW = 0;

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if ((i + j) % 2 == 0 && chess[i][j] == 'W') {
				++cntBW;
			}
			if ((i + j) % 2 == 1 && chess[i][j] == 'B') {
				++cntBW;
			}
			if ((i + j) % 2 == 0 && chess[i][j] == 'B') {
				++cntWB;
			}
			if ((i + j) % 2 == 1 && chess[i][j] == 'W') {
				++cntWB;
			}
		}
	}

	return min(cntWB, cntBW);
}

void in(int x, int y)
{
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			chess[i][j] = map[x + i][y + j];
		}
	}
}

int main()
{
	int n, m;
	int cnt_min = 2601;

	cin >> n;
	cin >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i <= n - 8; ++i) {
		for (int j = 0; j <= m - 8; ++j) {
			in(i, j);
			cnt_min = min(cnt_min, solve());
		}
	}

	cout << cnt_min << endl;

	return 0;
}