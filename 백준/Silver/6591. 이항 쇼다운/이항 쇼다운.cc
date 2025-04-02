#include <iostream>
using namespace std;

long long combination(int n, int k) {
    if(k > n) 
		return 0;

    if(k > n - k) 
		k = n - k;
    
	long long result = 1;
    
	for(int i = 1; i <= k; i++){
        result = result * (n - i + 1) / i;
    }
    return result;
}

int main() {
	int a, b;
	
	while (cin >> a >> b){
		if (a == 0 && b == 0)
			break;
		cout << combination(a, b) << endl;
	}
	return 0;
}