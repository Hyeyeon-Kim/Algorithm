#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int m;
    int cup[4] = {0,1,2,3};
    cin >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        if (a == b)
            continue;
        
        swap(cup[a], cup[b]);
        // for (int i=1; i <= 3; i++)
        //     cout << cup[i] << " ";
        // cout << endl;
    }

    // int ans = 0;
    for (int i=1; i <= 3; i++){
        if (cup[i] == 1)
            cout << i;
    }
}