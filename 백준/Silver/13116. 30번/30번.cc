#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--){
	int a, b;

	cin >> a >> b;

	int al = log2(a) + 1;
	int bl = log2(b) + 1;

	if (al < bl){
		swap(al, bl);
		swap(a, b);
	}

	while (al != bl){
		a /= 2;
		al--;
	}

	while (a != b){
		a /= 2;
		b /= 2;
	}

	cout << a*10 << endl;
	}
	return 0;
}