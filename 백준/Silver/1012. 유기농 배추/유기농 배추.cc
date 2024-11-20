#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;

stack<pair<int, int>> s;
int n = 0, m = 0, k = 0;
int cabbage[51][51] = { 0 };
int x = 0, y = 0;
int next_x[4] = { -1,0,1,0 };
int next_y[4] = { 0,1,0,-1 };

void check(int x, int y, int num)
{
	cabbage[y][x] = num;

	for (int i = 0; i < 4; i++)
	{
		int nextx = x + next_x[i];
		int nexty = y + next_y[i];

		if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n)
		{
			if (cabbage[nexty][nextx] == 1)
				check(nextx, nexty, num);
		}
	}
}

int main()
{
	int t = 0;

	cin >> t;

	for (int c = 0; c < t; c++)
	{

		cin >> m >> n >> k;

		memset(cabbage, 0, sizeof(int));

		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			cabbage[y][x] = 1;
		}

		int cnt = 0;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (cabbage[j][i] == 1)
				{
					cnt++;
					check(i, j, cnt + 1);
				}
			}
		}

		cout << cnt<< endl;
	}
}
