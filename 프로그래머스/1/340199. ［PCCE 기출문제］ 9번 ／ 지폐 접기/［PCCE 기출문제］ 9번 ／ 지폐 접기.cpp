#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 무조건 h가 작다고 가정 가로, 세로

void swap(vector<int> &obj){
    if (obj[0] >= obj[1])
        return ;
    int tmp = obj[0];
    obj[0] = obj[1];
    obj[1] = tmp;
}

bool is_done(int w_w, int w_h, int b_w, int b_h){
    if (b_h <= w_h && b_w <= w_w)
        return true;
    return false;
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    // cout << tmp[0] << " " << tmp[1];
    swap(wallet);
    swap(bill);
    
    while (is_done(wallet[0], wallet[1], bill[0], bill[1]) == 0){
        bill[0] /= 2;
        swap(wallet);
        swap(bill);
        answer++;
        cout << wallet[0] << " " << wallet[1] << " " << bill[0] << " " <<bill[1]<< "\n";
    }
    
    return answer;
}