#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	vector<vector<int>> map;

	cin >> n >> m;
	map.resize(n + 1);
	map[0].resize(m + 1);

	for (int i = 1; i <= n; i++)
	{
		string s;

		cin >> s;
		map[i].resize(m + 1);
		
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = s[j-1] - '0';
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 1)
				map[i][j] = min(map[i - 1][j - 1], min(map[i - 1][j], map[i][j - 1])) + 1;
		}
	}

	int max_len = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (max_len < map[i][j])
				max_len = map[i][j];

	cout << max_len * max_len;
}