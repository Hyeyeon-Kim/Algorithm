#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool com(pair<double,int>&a, pair<double,int>&b){
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector <int> user(N+1);
    
    for (int stage: stages){
        user[stage-1]++;
    }
    
    double chalinger = (double)stages.size();
    
    vector <pair<double,int>> fail(N);
    // double tmp;
    
    for (int i = 0; i < N; i++){
        if (!user[i] && !chalinger)
            fail[i] = {0, i+1};
        else
            fail[i] = {user[i] / chalinger, i+1};
        // tmp = user[i] / chalinger;
        // cout << user[i] << "/" << chalinger << "="<< tmp << "\n";
        chalinger -= user[i];
    }
    
    sort(fail.begin(), fail.end(),com);
    vector<int> answer;
    
    for (auto f : fail){
        answer.push_back(f.second);
        // cout << f.first << " " << f.second << endl;
    }
    
    return answer;
}