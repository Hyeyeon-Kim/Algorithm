#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int map[50][50];
string s[50];

int square(int size){

    if (size < 0)
        return 0;
    
    for(int i = 0; i + size < n; i++){
        for (int j = 0; j + size < m; j++){
            
            // printf("%d (%d, %d) (%d, %d) (%d, %d) (%d, %d)\n", size, i, j, i, j+size, i+size, j, i+size,j+size);
            // cout << map[i][j]  << " " << map[i+size][j]  << " " << map[i][j+size] <<" " << map[i+size][j+size] << " \n" ;
            // cout << (map[i][j] == map[i+size][j]) << endl;
            // cout << (map[i][j+size] == map[i+size][j+size]) << endl;
            // cout << (map[i][j] == map[i+size][j+size]) << endl;
            if ((map[i][j] == map[i+size][j]) &&  (map[i][j+size] == map[i+size][j+size]) && (map[i][j] == map[i+size][j+size])){
                // cout << " jhello\n";
                return size;
            }
        }
    }
   return square(size-1);
}

int main(){

    cin >> n >> m;

    for (int i =0; i < n;i++){
            cin >> s[i];
    }

    for (int i =0; i < n; i++){
        for (int j =0; j < m; j++){
            map[i][j] = s[i][j] - '0';
        }
    }

    int size  = square(min(n-1,m-1)) + 1;
    cout << size*size;
}