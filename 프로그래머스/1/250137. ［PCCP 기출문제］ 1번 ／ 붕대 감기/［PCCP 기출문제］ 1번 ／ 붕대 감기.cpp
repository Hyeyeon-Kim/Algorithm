#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int n = attacks.size();
    int timeline[1001] ={0};
    int now = health;
    
    cout << "now diff now now\n";
    
    int pre = 0;
    for (int i = 0; i < n; i++){
        
        //최대 체력 고려 
        int diff = attacks[i][0] - pre - 1;
        int charge = 0;
        
        cout << now << "   " << diff << "   ";
        
        if (now + diff >= health){
            // charge = health - now;
            now = health;
        }
        else{
            charge = diff * bandage[1];
            int bonus = (diff / bandage[0]) * bandage[2];
            now = (now + bonus + charge) < health ? (now + bonus + charge) : health;
        }
        
        cout << now << "   ";
        
        now -= attacks[i][1];
        pre = attacks[i][0];
        
        cout << now << "\n";
        if (now <= 0)
            return -1;
    }
    return now;
}
    
    /*
    
     2   9   10  11
     10  15  5   5
     0   5   0   0
     0   5   0   0
     
 30  20  15  10  5
    */
    
//     for (auto attack : attacks){
//         int i = attack[0];
//         int pow = attack[1];
        
//         timeline[i] = -pow;
//     }
    
//     int min_ = 0;
    
//     // 4 8 12 16 20 24 
    
//     for (int i = bandage[0]; i <= attacks[n-1][0]; i += bandage[0]){
//         while (i <= attacks[n-1][0] && i >= attacks[min_][0]){
//             i += attacks[min_][0];
//             min_++;
//         }

//         timeline[i] = bandage[2];
//         // cout << timeline[i] << " ";
        
//         cout << i << " ";
//     }
    
//     cout  << "\n";
    
//     for (int i = 1; i <= attacks[n-1][0]; i++){
//             cout << timeline[i] << " ";
//     }
    
//     cout  << "\n";
    
//     for (int i = 1; i <= attacks[n-1][0]; i++){
//         health += timeline[i];
        
//         if (timeline[i] >= 0 && health < max_)
//               health += bandage[1];
//         if (health <= 0)
//             return -1;
        
//         cout << health << " ";
//     }
    
//     return health;
// }
/*
[4, 2, 7]	20	[[1, 15], [5, 16], [8, 6]]	-1
	0 0 -10 0 0 0 0 5 0 -15 -5 -5 
    
3 2 7

2 9 10 11
7 1 1 

0 1 2 2 


3 7 47   5
4 40

0 5 10 15 20 25
7 


7 
*/