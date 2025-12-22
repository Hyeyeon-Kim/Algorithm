#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n+2);
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int s: reserve)
        student[s] = 1;
    
    vector <int> exception(n+1);
    
    for (int s : lost){
        if (student[s]){
            student[s] = 0;
            exception[s] = 1;
        }
    }
    
    int answer = n;
    
    for (int s : lost){
        if (exception[s])
            continue;
        if (student[s-1]){
            student[s-1] = 0;
            continue;
        }
        if (student[s]){
            student[s] = 0;
            continue;
        }
        if (student[s+1]){
            student[s+1] = 0;
            continue;
        }
        answer--;
    }
    
    
    return answer;
}