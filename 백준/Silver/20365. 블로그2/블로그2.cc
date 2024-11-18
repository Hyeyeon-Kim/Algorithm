#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string s;

    cin >> n;
    cin >> s;   

    int r  = 0, b = 0;

    for (int i = 0; i < n; i++){
        if (s[i] != s[i+1] && s[i] == 'R')
            r++;
        else if(s[i] != s[i+1] && s[i] == 'B')
            b++;
    }

    char tar = 'R';
    if (r < b)
        tar = 'B';
    
    int ans = 1;
    
    for (int i = 0; i < n; i++){
        if (s[i] != s[i+1] && s[i] != tar)
            ans++;
    }

    cout << ans;
 
}

// 7
// RBBRBR
// 3    