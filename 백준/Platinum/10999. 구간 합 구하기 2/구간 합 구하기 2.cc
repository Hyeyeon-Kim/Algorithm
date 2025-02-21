#include <iostream>
using ll = long long;
using namespace std;

ll tree[1 << 22];
ll lazy[1 << 22] = {0};
ll num[1 << 20];

ll init(int node, int start, int end){
    if (start == end)
        return tree[node] = num[start];
    
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void lazyUpdate (int node, int start, int end){
    if (lazy[node] == 0)
        return;
    
    tree[node] += (end - start + 1) * lazy[node];

    if (start != end){
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

ll sum (int node, int start, int end, int left, int right){
    lazyUpdate(node, start, end);

    if (left > end || right < start)
        return 0;

    if (left <= start && right >= end)
        return tree[node];

    int mid = (start + end) / 2;

    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int left, int right, long long d){
    lazyUpdate(node, start, end);

    if (left > end || right < start)
        return ;


    if (left <= start && right >= end){
        tree[node] += (end - start + 1) * d;
        
        if (start != end){
            lazy[node * 2] += d;
            lazy[node * 2 + 1] += d;
        }
        return ;
    }
    
    int mid = (start + end) / 2;
    
    update(node * 2, start, mid, left, right, d);
    update(node * 2 + 1, mid + 1, end, left, right, d);

    tree[node] = tree[node * 2] + tree[node * 2 + 1]; 
}

void print(int n){
    for (int i = 1; i <= n * 4; i++){
        cout << tree[i] << " ";
    } 
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    
    init(1, 1, n);
    // print(n);
    for (int i = 0; i < m +k; i++){
        int a, b, c;
        ll d;

        cin >> a;

        if (a == 1){
            cin >> b >> c >> d;
            update(1, 1, n, b, c, d);
        }
        else{
            cin >> b >> c;
            cout << sum(1, 1, n, b, c) << "\n";
        }   
        // print(n);
    }
}