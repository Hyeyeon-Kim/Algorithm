#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int  n, m, k;
ll tree[1 << 22] = {0};
ll lazy[1 << 22] = {0};
ll arr[1 << 20];

ll init(int node, int start, int end){
    if (start == end){
        tree[node] = arr[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
    return tree[node];
}

void lazy_update(int start, int end, int node){
    if (lazy[node] == 0)
		return;

    tree[node] += (end - start + 1) * lazy[node];
	if (start != end)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

ll sum(int node, int start, int end, int left, int right){
    lazy_update(start, end, node);

    if (end < left || start > right)
        return 0;
    
    if (left <= start && right >= end)
        return tree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, ll cal, int left, int right){
    lazy_update(start, end, node);
    
    if (end < left || start > right)
        return ;

    if (left <= start && right >= end){
        tree[node] += (end - start + 1) * cal;
		if (start != end)
		{
			lazy[node * 2] += cal;
			lazy[node * 2 + 1] += cal;
		}
		return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, cal, left, right);
    update(node * 2 + 1, mid + 1, end, cal, left, right);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    init(1, 1, n);

    for (int i = 0; i < m + k; i++){
        int a, b, c;
        ll d;

        cin >> a;

        if (a == 1){
            cin >> b >> c >> d;
            update (1, 1, n, d, b, c);
        }
        else{
            cin >> b >> c;
            cout << sum(1, 1, n, b, c) << '\n';
        }
    }   

}