#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
 
// int arr[2];
vector<int> answer;
set<int> tmp;
int n;

void combi(int idx, int pre, int sum, vector<int> &numbers){
    if (idx == 2){
        tmp.insert(sum);
        // cout << sum << " ";
        return;
    }
    
    for (int i = pre; i < n; i++){
        combi(idx+1, i+1, sum + numbers[i], numbers);
    }
}

vector<int> solution(vector<int> numbers) {
    n = numbers.size();
    
    combi(0, 0, 0, numbers);
    for (int n : tmp){
        answer.push_back(n);
    }
    // sort(answer.begin(), answer.end());
    return answer;
}