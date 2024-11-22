#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int visit[100001] = { 0 };
	int n, k;
	cin >> n >> k;
	queue<int> q;

	q.push(n);

	int dep = 0;
	while (!(q.empty()))
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int move = q.front();
			q.pop();

			if (move == k)
			{
				cout << dep;
				return (0);
			}

			if (move - 1 >= 0 && visit[move-1] == 0)
			{
				q.push(move - 1);
				visit[move - 1] = 1;
			}
			if (move + 1 <= 100000 && visit[move + 1] == 0)
			{
				q.push(move + 1);
				visit[move + 1] = 1;
			}
			if (move * 2 <= 100000 && visit[move * 2] == 0)
			{
				q.push(move * 2);
				visit[move * 2] = 1;
			}
		}
		dep++;
	}
	cout << dep;
}