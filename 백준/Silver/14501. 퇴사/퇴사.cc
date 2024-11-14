#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[15][2];
int max_ = 0;

void dfs(int day, int revenue)
{
    if (day > n)
        return;
    if (day == n)
    {

        if (revenue > max_)
            max_ = revenue;
        return ;
    }

    dfs(day + 1, revenue);
    dfs(day + arr[day][0], revenue + arr[day][1]);
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1];
    dfs(0, 0);
    cout << max_;
}