#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    
    int max_ = max(max(a,b), c);
    int min_ = min(min(a,b), c);
    
    if (max_ == a){
        if (min_ == b)
            cout << c;
        else
            cout << b;
    }
    else if (max_ == b){
        if (min_ == a)
            cout << c;
        else
            cout << a;
    }
    else{
        if (min_ == a)
            cout << b;
        else
            cout << a;
    }
}