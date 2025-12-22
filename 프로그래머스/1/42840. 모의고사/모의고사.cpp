#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool tmp(pair<int, int>&a, pair<int, int>&b){
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

vector<int> solution(vector<int> answers) {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<pair<int, int>> score(3);
    
    score[0] = {0, 1};
    score[1] = {0, 2};
    score[2] = {0, 3};
    
    for (int i = 0; i < answers.size(); i++){
        if (answers[i] == a[i % 5])
            score[0].first++;
        if (answers[i] == b[i % 8])
            score[1].first++;
        if (answers[i] == c[i % 10])
            score[2].first++;
    }
    
    // cout << score[0].first;
    
    sort(score.begin(), score.end(), tmp);
    
    vector<int> answer;
    int max_ = score[0].first;
    
    
    for (int i =0 ; i < 3; i++){
        if(score[i].first == max_)
            answer.push_back(score[i].second);
    }
    
    return answer;
}