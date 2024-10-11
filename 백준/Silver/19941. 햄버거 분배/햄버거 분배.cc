#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int n, k;

    cin >> n >> k;
    cin >> s;

    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'P')
        {
            for (int j = i - k; j <= i + k; j++)
            {
                if ((j >= 0 && j < n ) && s[j] == 'H')
                {
                    s[j] = 'h';
                    cnt++;
                    break;
                }
            }
        }
    }
    
    cout << cnt;

    return 0;
}