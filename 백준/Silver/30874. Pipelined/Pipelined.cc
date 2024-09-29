#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
    int n;
    int s[200001];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int max_ = 0;
    int idx = 0;
    
    for (int i = 0; i < n; i++){
        if (max_ < s[i]){
            max_ = s[i];
            idx = i;
        }
    }

    cout << max_ + n-1;
   return 0;
}