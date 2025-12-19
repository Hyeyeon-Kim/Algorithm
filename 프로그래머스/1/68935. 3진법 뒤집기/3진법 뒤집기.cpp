#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n) {
    string s;
    
    while (n){
        s += (n % 3) + '0';
        n = n / 3;
    }
    
    int answer = 0;
    
    for (int i = s.size()-1; i >= 0; i--){
    // int i = 1;    
    answer += (s[i] - '0') * pow(3, s.size()-1-i); 
    // cout << answer;
    }
    
    cout << s;
    
    return answer;
}