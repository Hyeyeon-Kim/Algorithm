#include <iostream>
#define MAX 1000000001
using namespace std;

int n;
int arr[11];
int oper[4];

int maxx = -MAX;
int minn = MAX;

void dfs(int plus, int minus, int multi, int divi, int cnt, int sum)
{
	if (cnt == n)
	{
		maxx = max(maxx, sum);
		minn = min(minn, sum);
		return;
	}
	if (plus > 0)
		dfs(plus - 1, minus, multi, divi, cnt + 1, sum + arr[cnt]);
	if (minus > 0)
		dfs(plus, minus -1, multi, divi, cnt + 1, sum - arr[cnt]);
	if (multi > 0)
		dfs(plus, minus, multi - 1, divi, cnt + 1, sum * arr[cnt]);
	if (divi > 0)
		dfs(plus, minus, multi, divi - 1, cnt + 1, sum / arr[cnt]);

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	dfs(oper[0], oper[1], oper[2], oper[3], 1, arr[0]);

	cout << maxx << endl;
	cout << minn << endl;
}