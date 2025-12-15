#include <string>
#include <vector>
#include <iostream>
using namespace std;

int a, b, n;
int ans;
void re(int bottle){
    // cout << bottle << " " << ans << "\n"; 
    if (bottle < a)
        return;
    
    int full = (bottle / a) * b;
    ans += full;
    int emp = bottle % a;
    re(full + emp);
}

int solution(int a_, int b_, int n_) {
    a = a_;
    b = b_;
    n = n_;
    
    re(n);
    return ans;
}