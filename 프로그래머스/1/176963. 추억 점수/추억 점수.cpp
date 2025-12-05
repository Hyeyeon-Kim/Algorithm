#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> person;
    int n = name.size();
    
    for (int i = 0; i < n; i++){
        person.insert({name[i], yearning[i]});
    }
    
    answer.resize(photo.size());
    
    for (int i = 0; i < photo.size(); i++){
        int score = 0;
        
        for (string s : photo[i]){
            score += person[s];
        }
        answer[i] = score; 
    }
    
    return answer;
}