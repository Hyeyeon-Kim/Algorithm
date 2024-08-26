#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int n;
    vector <int> p;
    vector <int> m;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;

        cin >> num;
        if (num > 0) 
            p.push_back(num);
        else 
            m.push_back(num); 
    }
    

    sort(p.begin(), p.end(), greater<int>());   
    sort(m.begin(), m.end());  

    int sum = 0;    
    
    if (p.size() != 0)
    {
        if (p.size() % 2 != 0) 
        sum += p[p.size() - 1];   

        for (int i = 0; i < p.size() - 1; i+= 2)
        {        
            if (p[i + 1] == 1) 
                sum += p[i] + p[i + 1];        
            else if (p[i + 1] > 0) 
                sum += p[i] * p[i + 1];              
        }  
    }   
    
    if (m.size() != 0)
    {
        if (m.size() % 2 != 0 && m.size() != 0) 
        sum += m[m.size() - 1];  

        for (int i = 0; i < m.size() - 1; i+=2)        
            sum += m[i] * m[i + 1];    
    }  

    cout << sum;
}