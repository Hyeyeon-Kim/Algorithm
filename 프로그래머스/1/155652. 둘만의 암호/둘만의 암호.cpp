#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <unordered_map>
using namespace std;

string solution(string s, string skip, int index) {
    sort(skip.begin(), skip.end());
    deque<char> de(skip.begin(), skip.end());    
    
    unordered_map<char, int> alpha1;
    vector<char> alpha2;
    
    int cnt = 0;
    for (int i = 0; i < 26; i++){
        char c = i + 'a';
        
        if (!de.empty() && c == de.front()){
            de.pop_front();
            continue;
        }
        
        alpha1[i + 'a'] = cnt++;
        alpha2.push_back(i + 'a');
    }
    
    
    
    for (char c : alpha2)
        cout << c << " ";
    cout << endl;
    
    string answer = "";
    
    for (char c : s){
        cout << (alpha1[c]) << " " << (alpha1[c] + index) << " " << cnt << " " << ((alpha1[c] + index) % cnt) << endl;
        int idx = (alpha1[c] + index) % cnt;
        answer += alpha2[idx];
    }

    return answer;
}