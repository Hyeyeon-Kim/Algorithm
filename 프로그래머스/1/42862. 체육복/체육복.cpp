#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> clothes(n+1, 1);
    
    for (int r: reserve)
        clothes[r]++;
    
    for (int l : lost)
        clothes[l]--;
    
    
    for (int i = 1; i <= n; i++){
        if (clothes[i])
            continue;
        if ( i > 1 && clothes[i - 1] == 2){
            clothes[i - 1]--;
            clothes[i]++;
        }
        else if (i < n && clothes[i + 1] == 2){
            clothes[i+1]--;
            clothes[i]++;
        }
    }
    
    int answer = 0;
    
    for (int i = 1; i <= n; i++){
        if (clothes[i])
        answer++;
    }
    
    
    return answer;
}