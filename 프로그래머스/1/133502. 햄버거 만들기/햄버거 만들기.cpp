#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


// 1 3 2 1 3 2 1 1 2
int solution(vector<int> ingredient) {
    deque<int> de;
    int ans = 0;
    
    for (int i: ingredient){
        // if (i != 1 || de.size() < 4)
        de.push_front(i);
        if (de.size() >= 4) {
            // cout << de[0] << " " << de[1] << " " << de[2] << " " << de[3] << "\n";
            if (de[0] == 1 & de[1] == 3 & de[2] == 2 & de[3] == 1){
                cout << "dd";
                ans += 1;
                for (int j = 0; j < 4; j++)
                    de.pop_front();
            }
        }
    }
    
    
    // for (int a: de)
    //     cout << a << " ";
    
    return ans;
}