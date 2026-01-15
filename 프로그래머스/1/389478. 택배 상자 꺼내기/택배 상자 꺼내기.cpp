#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int w, int num) {
    int h = (num - 1) / w;      
    
    int cnt = 0;
    while (n >= num){
        if (h % 2 == 0){
            int col =  w - 1 - ((num - 1) % w);
            num += col * 2 + 1;
        }
        else{
            int col = (num - 1) % w;
            num += (w - col) * 2 - 1;
        }
        cnt++;
        // cout << num << " ";
    }

    return cnt;
}