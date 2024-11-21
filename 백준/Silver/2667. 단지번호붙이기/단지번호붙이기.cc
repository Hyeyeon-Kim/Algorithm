#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string apart[25];

int next_x[4] = { -1,0,1,0 };
int next_y[4] = { 0,1,0,-1 };
vector <int> house;
int cnt;
int n;
int index = 1;


void check(int x, int y)
{
	cnt++;
	apart[x][y] = index + '0';


	for (int i = 0; i < 4; i++)
	{
		int nextx = x + next_x[i];
		int nexty = y + next_y[i];

		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n)
		{
			if (apart[nextx][nexty] == '1')
				check(nextx, nexty);
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> apart[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (apart[i][j] == '1')
			{
				cnt = 0;
				index++;
				check(i, j);
				house.push_back(cnt);
			}
		}
	}

	sort(house.begin(), house.end());

	cout << index - 1 << endl;
	for (int i = 0;i < house.size(); i++)
		cout << house[i] << endl;
}