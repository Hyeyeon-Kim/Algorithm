#include <string>
#include <vector>

using namespace std;

int col(long long num, int deep, int cnt){
    if (num <= 1)
        return cnt;
    
    if (deep == 500)
        return -1;
    
    if (num % 2 == 0)
        return col(num/2, deep+1, cnt+1);
    else
        return col(num*3+1, deep+1, cnt+1);
}

int solution(int num) {
    return col(num, 0, 0);
}