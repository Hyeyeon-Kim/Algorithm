#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size());
    
    unordered_map<char, int> alpha;
    
    for (int i = 0; i < keymap.size(); i++){
        int  j = 1;
        
        for (char key : keymap[i]){
            if (alpha.find(key) == alpha.end()) 
                alpha[key] = j;
            else if (alpha[key] > j)
                alpha[key] = j;
            j++;
        }
    }
     
    for (int i = 0; i < targets.size(); i++){
        bool can = true;
        
        for (char tar: targets[i]){
            if (alpha.find(tar) == alpha.end()){
                can = false;
                break;
            }
                
            answer[i] += alpha[tar];
            // cout << alpha[tar] << " ";
        }
        if (!can)
            answer[i] = -1;
        // cout << endl;
    }
    
    return answer;
}