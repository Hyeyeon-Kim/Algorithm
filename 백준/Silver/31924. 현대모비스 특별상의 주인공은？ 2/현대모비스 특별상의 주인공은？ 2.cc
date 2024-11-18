#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int n;
string input[100];
int use[100][100] = {0};

int next_x[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int next_y[] = {0, 0, 1, -1, -1, 1, -1, 1};
char word[] = {'O','B', 'I', 'S'};
int ans = 0;

void dfs(int x, int  y)
{
    // cout << input[x][y] << "\n";
    use[x][y] = 1;

    for (int i = 0; i < 8; i++){
        int cnt = 0;
        for (int j = 1; j < 5; j++){
            int nx = next_x[i]*j + x ;
            int ny = next_y[i]*j + y;

            if (nx < 0 || ny < 0 || ny >= n || nx >= n)
                continue;
            
            // cout << input[nx][ny] << " "; 
            if (input[nx][ny] != word[j-1])
                continue;

            cnt++;
        }
        // cout << endl;
        // cout << cnt << endl;
        if (cnt == 4)
            ans++;
    }
}

int main()
{
    cin >> n;

    for (int i =0 ; i < n; i++)
        cin >> input[i];
    
    for (int i =0 ; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            // cout << input[i][j] << " ";
            if (use[i][j] == 0 && input[i][j] == 'M')
                dfs(i, j);
        }
        // cout << endl;
    }

    cout << ans;
}
// 100 * 100 * 8 * 5

// 양옆 대각선
// m을 찾고 5칸 이동했을 떄 모비스인지 확인 