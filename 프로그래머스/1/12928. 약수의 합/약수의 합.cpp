#include <string>
#include <vector>
#include <cmath>
using namespace std;

int GDC(int n){
    int sum  = 0;
    
    for (int i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            sum += i;
            if (n / i != i)
                sum += n / i;
        }
    }
    return sum;
}

int solution(int n) {
    return GDC(n);
}