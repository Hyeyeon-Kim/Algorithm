#include <iostream>
#include <queue>
#include <algorithm>
#include <algorithm>
using namespace std;
 

int main() {
	int n, t;
	int cur, ret;
	
    cin >> n;
	vector <int> arr(n);

    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    

    int ans=0, mxindex = n-1, cnt = 0;

    sort(arr.begin(), arr.end());

    while (mxindex > cnt)
    {
        arr[cnt]--;
        if(arr[cnt] == 0) 
			cnt++;
        mxindex -= 1;
        ans++;
    }
    cout << ans <<'\n';
    
}