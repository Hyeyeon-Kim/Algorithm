#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool com (vector<int> &v1, vector <int> &v2){
    if (v1[1] == v2[1])
		return v1[0] < v2[0];
	else 
        return v1[1] < v2[1];
}

int solution(vector<vector<int>> targets) {
    
    sort(targets.begin(), targets.end(), com);
    
    int answer = 0;
    int i = 0;
    
    while(i < targets.size()){
        answer++;
        int e = targets[i][1];
        i++;
        
        while (i < targets.size() && e > targets[i][0])
            i++;
    }
    return answer;
}