#include <string>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(long long n) {
    
    double s = sqrt(n);
    if (s == (long long) s)
        return pow(s+1, 2);
    return -1;
}