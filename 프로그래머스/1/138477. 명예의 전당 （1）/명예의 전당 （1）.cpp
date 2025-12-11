#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer(score.size());
    
    for (int i = 0; i < score.size(); i++){
        if (i < k)
            q.push(score[i]);
        else if (q.top() < score[i]){
            q.pop();
            q.push(score[i]);
        }
        answer[i] = q.top();
    }
    

    return answer;
}