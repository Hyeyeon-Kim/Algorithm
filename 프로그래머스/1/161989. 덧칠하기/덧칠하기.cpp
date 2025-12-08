#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    stack<int> s;

    
    for (int i = section.size()-1; i >= 0 ; i--){
        s.push(section[i]);
    }
    
    while (!s.empty()){
        int num = s.top();
        s.pop();
        
        while (!s.empty() && s.top() - num < m){
            // cout << s.top() << " ";
            s.pop();
        }
        
        // cout << endl;
        
        answer++;
    }
    
    return answer;
}

// 0 1 3 