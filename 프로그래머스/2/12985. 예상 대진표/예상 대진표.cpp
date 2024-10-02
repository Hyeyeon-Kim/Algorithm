#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, int a, int b)
{
    int cnt = 1;
    
    a--;
    b--;

    while(1){
        if(a/2 == b/2)
            break;
        a /= 2;
        b /= 2;
        cnt++;
    }
//         if (a/2 + 1 == b/2 && a%2 == 1)
//             break;
//        cout << (a/2 + 1 == b/2) << " " << (a%2 == 1) << endl;
//         a /= 2;
//         b /= 2;
//      cout << a << " " << b << endl << endl;
    
//      cout << (a/2 + 1 == b/2) << " " << (a%2 == 1) << endl;
//         a /= 2;
//         b /= 2;
//      cout << a << " " << b << endl << endl;
    
    
//      cout << (a/2 + 1 == b/2) << " " << (a%2 == 1) << endl;
//         a /= 2;
//         b /= 2;
//      cout << a << " " << b << endl << endl;
    
    

    

    return cnt;
}