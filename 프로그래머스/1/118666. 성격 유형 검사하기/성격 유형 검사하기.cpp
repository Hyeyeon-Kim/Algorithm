#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

// vector<int> mbti(26);

char mbti[4][2] = {{'R','T'},{'C','F'},{'J','M'},{'A','N'}};

string solution(vector<string> survey, vector<int> choices) {
    map<char, int> score;
    
    for (int i = 0; i < survey.size(); i++)
    {
        string type = survey[i];
        
        if (choices[i] < 5)
            score[type[0]] += (4 - choices[i]);
        else
            score[type[1]] += (choices[i] % 4);
    }
    
        string answer = "";
    
        for (int i = 0; i < 4; i++){
            auto type = mbti[i];

            if (score[type[0]] < score[type[1]])
                answer += type[1];
            else
                answer += type[0];
            
        }
        cout << endl;
    
    return answer;
}