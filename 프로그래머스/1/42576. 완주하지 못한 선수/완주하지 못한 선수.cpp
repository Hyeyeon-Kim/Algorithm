#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    
    for(string p : participant) {
        if (m.find(p) == m.end())
            m[p] = 0;
        else
            m[p]++;
    }
    
    for (string c : completion){
        m[c]--;
    }
    
    string answer = "";
    
    for (auto p : m){
        if (p.second == 0)
            answer = p.first;
    }
    return answer;
}