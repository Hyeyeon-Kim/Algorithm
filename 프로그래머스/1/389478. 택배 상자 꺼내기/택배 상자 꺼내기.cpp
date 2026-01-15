#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int w, int num) {
    // num = 1;
    vector<vector<int>> box(n / w + 1, vector<int>(w));
    
    for (int i = 0; i < n; i++){
        
        int ii = i / w;
        int j = i % w;
        
        // cout << ii << " " << j << "   ";
        if (ii % 2 == 0)
            box[ii][w-1-j] = i+1;
        else{
            box[ii][j] = i+1;
        }
    }
    
    int h = (num-1) / w, ww;
    if (h % 2 == 0)
        ww = w - 1 - ((num-1) % w);
    else
        ww = (num-1) % w;;
        
   cout << h << " " << ww << "   \n";
    int cnt = 0;
    
    for (int i = h; i <= n / w; i++){
        cout << box[i][ww] << " ";
        if (box[i][ww])
            cnt++;
    }    
    return cnt;
}