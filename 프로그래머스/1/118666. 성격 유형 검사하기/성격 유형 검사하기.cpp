#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> mbti(26); 

string find_idx(int i){
    if (i == 0)
        return "RT";
    else if (i == 1) 
        return "CF";
    else if (i == 2)
        return "JM";
    else
        return "AN";
}

string solution(vector<string> survey, vector<int> choices) {
    
    for (int i = 0; i < survey.size(); i++)
    {
        string type = survey[i];
        
        int ignore = type[0] - 'A';
        int agree = type[1] - 'A';
        
        if (choices[i] < 5)
            mbti[ignore] += (4 - choices[i]);
        else
            mbti[agree] += choices[i] % 4;
    }
    
        string answer = "";
    
        for (int i = 0; i < 4; i++){
        string type = find_idx(i);
        cout << type << "\n" <<  mbti[type[0]- 'A'] << " " << mbti[type[1] - 'A'] << "\n";
        if (mbti[type[0] - 'A'] < mbti[type[1] - 'A'])
            answer += type[1];
        else
            answer += type[0];
            
        }
        cout << endl;
    
    return answer;
}