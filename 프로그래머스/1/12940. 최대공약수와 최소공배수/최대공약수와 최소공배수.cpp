#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> solution(int n, int m) {
    int a = max(n,m), b = min(n,m);
    
    while (b){    
        int t = a % b;
        a = b;
        b = t;
    } 
    
    return {a, n * m /a};
}