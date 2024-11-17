#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[8];
int com[25] = {0};
int use[35] = {0};

void dfs(int depth){
    if (depth == n * 2){    
        for (int i = 0; i < n*2; i++)
            cout << com[i] << " ";
        cout << endl;
        exit(0);
    }

    if (com[depth] != -1) {
        dfs(depth + 1);
        return;
    }

    for (int i = 0; i < n; i++){
        if (!use[i] && depth + arr[i]+1 < n * 2 && com[depth+arr[i]+1] == -1){
            use[i] = 1;

            com[depth] = com[depth+arr[i]+1] = arr[i];

            dfs(depth+1);

            use[i] = 0;
            
            com[depth+arr[i]+1] = com[depth] = -1;
        }
    }
}

int main(){
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    memset(com, -1, sizeof(com));

    dfs(0);
    cout << -1;
}