#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int a, b, a_cnt = 0, b_cnt = 0;
    int stock[14];
    cin >> a;
    b = a;

    int up = 0;
    int down =0 ;
    for (int i = 0; i < 14; i++){
        cin >> stock[i];
        int a_buy = a/stock[i];
        a = a%stock[i];
        a_cnt += a_buy;

        if (i > 0 && stock[i] > stock[i-1]){
            down = 0;
            up++;
        }
        else if (i > 0 && stock[i] < stock[i-1]){
            up = 0;
            down++;
        }

        int b_buy=0 ;
        if(down == 3){
            b_buy = b/stock[i];
            b = b % stock[i];
            b_cnt += b_buy;
            down = 2;
        }
        else if (up == 3){
            up = 2;
            b += b_cnt * stock[i];
            b_cnt = 0;
        }
        // cout << up << " " << down;
        // cout << ": " << b_cnt << " " << b_buy << " " << b << endl;
        // cout << a_cnt << " " << a_buy << " " << a << endl;
    }

    a = a+stock[13]*a_cnt;
    b = b+stock[13]*b_cnt;

    if (a > b)
        cout << "BNP";
    else if (a < b)
        cout << "TIMING";
    else
        cout << "SAMESAME";
}