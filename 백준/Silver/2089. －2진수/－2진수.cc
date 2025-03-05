#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;

	cin >> n;
	
	if(n == 0){
        cout << 0;
        return 0;
    }
    
    vector<int> ans;
    
	while(n != 0){
        int r = n % (-2);
        n /= (-2);
        if(r < 0){
            r += 2;
            n++;
        }
        ans.push_back(r);
    }
    
    reverse(ans.begin(), ans.end());

    for(int digit : ans)
        cout << digit;
}