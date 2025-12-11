#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> alpha(26);
    vector<int> answer(s.size());
    
    int i = 1;
    
    for (char c : s){
        if (alpha[c - 'a'] == 0){
            answer[i-1] = -1;
        }
        else{
            answer[i-1] = i - alpha[c - 'a'];
        }
        // cout << alpha[c - 'a'] << " ";
        // cout << answer[i-1] << " ";
        
        alpha[c - 'a'] = i;
        i++;
    }
    
    // for (int i = 0; i < 5; i++)
    //     cout << answer[i] << " ";

    return answer;
}