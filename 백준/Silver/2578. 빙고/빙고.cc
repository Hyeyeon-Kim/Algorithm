#include <iostream>
using namespace std;

int board[5][5];

void check(int n)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0;j < 5;j++)
			if (n == board[i][j])
			{
				board[i][j] = 0;
				return;
			}
}

bool bingo()
{
	int cnt = 0;

	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += board[i][j];
		}
		if (sum == 0)
			cnt++;
	}


	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += board[j][i];
		}
		if (sum == 0)
			cnt++;
	}

	int sum = 0;
	for (int i = 0; i < 5; i++)
		sum += board[i][i];
	if (sum == 0)cnt++;


	sum = 0;
	for (int i = 0; i < 5; i++)
		sum += board[i][5 - 1 - i];
	if (sum == 0)cnt++;

	if (cnt >= 3)
		return true;
	else return false;
}

int main()
{
	int n;

	for (int i = 0; i < 5;i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];

	for (int i = 0; i < 25; i++)
	{
		cin >> n;

		check(n);
			
		if (bingo())
		{
			cout << i + 1 << endl;
			break;
		}
	}
}