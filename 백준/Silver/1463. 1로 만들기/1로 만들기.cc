#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	int n_arr[1000001] = { 0 };

	cin >> n;

	n_arr[1] = 0;
	n_arr[2] = 1;

	for (int i = 3; i <= n;i++)
	{
		n_arr[i] += n_arr[i - 1] + 1;
		if (i % 2 == 0)
			n_arr[i] = min(n_arr[i], n_arr[i / 2] + 1);
		if (i % 3 == 0)
			n_arr[i] = min(n_arr[i], n_arr[i / 3] + 1);
	}
	cout << n_arr[n];
}