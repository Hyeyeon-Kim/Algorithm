#include <string>
#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;

int solution(vector<int> ingredient) {
    vector<int> q;
    
    int ans = 0;
    
    for (int i = 0; i < ingredient.size(); i++){
        q.push_back(ingredient[i]);
        
        int size = q.size();
        
        if (size < 4)
            continue;
        
        if (q[size-1] == 1 && q[size-2] == 3 && q[size-3] == 2 && q[size-4] == 1){
            ans++;
            q.pop_back();
            q.pop_back();
            q.pop_back();
            q.pop_back();   
        }
    }

    return ans;
}