#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while (t--){
        string s;
        cin >> s;
        cout << s[0]<<s[s.length()-1]<< endl;
    }
}