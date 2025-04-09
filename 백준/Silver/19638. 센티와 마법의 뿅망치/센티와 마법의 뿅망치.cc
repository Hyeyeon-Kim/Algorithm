#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cen, cnt;
    cin >> n >> cen >> cnt;
    
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    
    int use = 0;
    while (cnt > 0 && !pq.empty()) {
        int top = pq.top();
        if (top < cen)
            break;
        if (top == 1)
            break;
        
        pq.pop();
        top /= 2;
        pq.push(top);
        use++;
        cnt--;
    }
    
    if (pq.top() < cen)
        cout << "YES\n" << use;
    else {
        cout << "NO\n" << pq.top();
    }
    
    return 0;
}
