#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int cnt = 0;

int press(string s, int count){
    
    if (s.length() == 1 && s[0] == '1')
        return count;
    
    int num = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '0')
            cnt++;
        else
            num++;      
    }
    
    string tmp;
    while (num){
        int t = num & 1;
        num >>= 1;
        if (t == 0)
            tmp += '0';
        else{
            tmp += '1';
        }
    }
    // cout << tmp << endl;
    return press(tmp, count+1);
}

vector<int> solution(string s) {
    vector<int> answer(2);
    // press(s, 0);
    answer[0] = press(s, 0);
    answer[1] = cnt;
    return answer;
}