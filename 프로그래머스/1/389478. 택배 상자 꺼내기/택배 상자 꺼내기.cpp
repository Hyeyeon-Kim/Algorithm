#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(int n, int w, int num) {
    
    int c;
    
    c = ((num-1) / w) % 2 == 0 ? ((num-1) % w) : w - ((num-1) % w) - 1;
    
    // cout << r << " " << c << endl;
    
    int cnt = 1;
    
    for (int i = num + 1; i <= n; i++){
        int idx;
    
        idx = ((i-1) / w) % 2 == 0 ? ((i-1) % w) : w - ((i-1) % w) - 1;
        
        if (idx == c)
            cnt++;
        
        // cout << (idx == c) << endl;
        
        // cout << i << ": " << idx << endl;
    }
    
    return cnt;
}

        //     cout << i+1 <<" : " << (i / w) << " "<< (i % w) << endl;
        // else
        //     cout << i+1 <<" : " << (i / w) << " "<< w  - (i % w) - 1<< endl;
