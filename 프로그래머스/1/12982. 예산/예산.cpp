#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int sum = 0;
    int i = 0;
    
    while (i < d.size() && sum + d[i] <= budget){
        // cout << d[i] << " ";
        sum += d[i];
        i++;
    }
    return i;
}