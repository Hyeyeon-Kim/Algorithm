#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

char sign[10];
int n;
int ans[10] = {0};
bool use[10] = {0};
string min_;
string max_;

void dfs(int cnt){
    if (cnt > 1){
        if (sign[cnt-2] == '>' && ans[cnt-2] < ans[cnt-1])
            return ;
        if (sign[cnt-2] == '<' && ans[cnt-2] > ans[cnt-1])
            return ;
    }

    if (cnt == n+1){
        string tmp;
        for (int i = 0; i < n+1; i++)
            tmp += ans[i] + '0';
        max_ = tmp;
        if (min_.length() == 0)
            min_ = max_;    
    }

    for (int i = 0; i < 10; i++){
        if (use[i])
            continue;
        use[i] = 1;
        ans[cnt] = i;
        dfs(cnt + 1);   
        use[i] = 0;
    }

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> sign[i];
    
    dfs(0);
    cout << max_ << endl << min_ ;
}   
