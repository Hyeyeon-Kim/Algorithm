#include <string>
#include <vector>
// #include <map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    set<string> word;
    
    for (int i = 0; i < words.size(); i++){
        if (i > 0 && words[i-1][words[i-1].length()-1] != words[i][0]){
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            break;
        }
        
        if(word.find(words[i]) == word.end()){
            word.insert(words[i]);
        }
        else{
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            break;
        }
    }

    return answer;
}