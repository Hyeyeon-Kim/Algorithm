#include <bits/stdc++.h>
using namespace std;

bool isValidTree(const string &s) {
    int len = s.size();
    if (len == 1) {
        return true;
    }
    
    int mid = len / 2;
    char root = s[mid];
    string left  = s.substr(0, mid);
    string right = s.substr(mid + 1);

    if (root == '0') {
        if (left.find('1') != string::npos || right.find('1') != string::npos) {
            return false;
        }
        return true;
    }
    return isValidTree(left) && isValidTree(right);
}

bool canRepresent(long long x){
    if (x == 0)
        return true;
    
    string bin;
    
    while (x > 0){
        bin.push_back(char('0' + (x&1)));
        x >>= 1;
    }
    reverse(bin.begin(), bin.end());
    
    int L = bin.size();
    int k = 0;
    while (( (1 << k) - 1 ) < L) {
        ++k;
    }
    int targetLen = (1 << k) - 1;
    
    if (targetLen > L) {
        bin = string(targetLen - L, '0') + bin;
    }

    return isValidTree(bin);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer(numbers.size());
    
    for (int i = 0; i < numbers.size(); i++){
        answer[i] = canRepresent(numbers[i]) ? 1 : 0;
    }
    
    return answer;
}