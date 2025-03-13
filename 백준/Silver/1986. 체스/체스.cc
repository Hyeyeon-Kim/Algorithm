#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> attacked(n, vector<int>(m, 0));
    vector<vector<bool>> piece(n, vector<bool>(m, false));
    
    // Queen 입력 및 기록
    int queenCount;
    cin >> queenCount;
    vector<pair<int, int>> queens;
    for (int i = 0; i < queenCount; i++){
        int r, c;
        cin >> r >> c;
        r--; c--;  
        queens.push_back({r, c});
        attacked[r][c] = 1;
        piece[r][c] = true;
    }
    
    int knightCount;
    cin >> knightCount;
    vector<pair<int, int>> knights;
    for (int i = 0; i < knightCount; i++){
        int r, c;
        cin >> r >> c;
        r--; c--;
        knights.push_back({r, c});
        attacked[r][c] = 1;
        piece[r][c] = true;
    }
    
    int pawnCount;
    cin >> pawnCount;
    for (int i = 0; i < pawnCount; i++){
        int r, c;
        cin >> r >> c;
        r--; c--;
        attacked[r][c] = 1;
        piece[r][c] = true;
    }
    
    int knight_moves[8][2] = {
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
    };
    for (auto &knight : knights){
        int r = knight.first, c = knight.second;
        for (int i = 0; i < 8; i++){
            int nr = r + knight_moves[i][0];
            int nc = c + knight_moves[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                attacked[nr][nc] = 1;
        }
    }
    
    int queen_dirs[8][2] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},
        {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
    };
    for (auto &queen : queens){
        int r = queen.first, c = queen.second;
        for (int d = 0; d < 8; d++){
            int dr = queen_dirs[d][0], dc = queen_dirs[d][1];
            int nr = r + dr, nc = c + dc;
            while(nr >= 0 && nr < n && nc >= 0 && nc < m){
                attacked[nr][nc] = 1;
                if(piece[nr][nc]) break;
                nr += dr;
                nc += dc;
            }
        }
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (attacked[i][j] == 0)
                ans++;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
