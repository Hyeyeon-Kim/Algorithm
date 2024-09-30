#include <iostream>
#include <string>
using namespace std;

int main(){
string a,b;
    cin >> a >> b;
    
    int acnt = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] == 'a')
            acnt++;
    int bcnt = 0;
    for (int i = 0; i < b.length(); i++)
        if (b[i] == 'a')
            bcnt++;
    
    if (acnt >= bcnt)
        cout << "go\n";
    else
        cout << "no\n";
}