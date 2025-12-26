#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    while (b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

vector<int> solution(int n, int m) {
    int g = gcd(n, m);
    int l = n / g * m;
    return {g, l};
}