#include <iostream>
using namespace std;

int number(long long idx){
	if (idx == 0)
		return 0;
	else if (idx == 1)
		return 1;
	else if (idx % 2 == 0)
		return number(idx / 2);
	else
		return 1 - number (idx / 2);
}

int main() {
	long long k;

	cin >> k;

	cout << number(k-1);
	return 0;
}
