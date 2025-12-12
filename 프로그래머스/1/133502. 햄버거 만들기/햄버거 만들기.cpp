#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

void pq(stack<int> s){
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int solution(vector<int> ingredient) {
    stack<int> s;

    int ans = 0;
    
    for (int i = 0; i < ingredient.size(); i++){
        s.push(ingredient[i]);
        
        if (s.size() < 4 || s.top() != 1)
            continue;    
        
        vector <int> ham(4);
    
        for (int j = 0; j < 4; j++){
            ham[j] = s.top();
            s.pop();
        }
        
        // for (int j = 0; j < 4; j++){
        //     cout << ham[j] << " ";
        // }
        // cout << endl;
        
        if (ham[0] == 1 && ham[1] == 3 && ham[2] == 2 && ham[3] == 1) 
            ans++;
        else{
            for (int j = 3; j >= 0; j--)
                s.push(ham[j]);
        }
    }
    return ans;
}



/*
2 1 1 2 3 1 2 3 1


2 ( 2 3 )(


2
1
3
1
2
1
2
3
1



*/