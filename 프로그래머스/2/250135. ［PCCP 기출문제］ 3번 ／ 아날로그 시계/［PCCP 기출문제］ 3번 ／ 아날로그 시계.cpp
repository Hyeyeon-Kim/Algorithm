#include <string>
#include <vector>
#include <iostream>
using namespace std;

int changeSecond(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}

vector <double> getDgree(int second){
    int h = second / 3600;
    int m = (second % 3600) / 60;
    int s = (second % 3600) % 60;
    
    vector <double> tmp (3);
    
    tmp[0] = 6 * s;
    tmp[1] = 6 * m + 0.1 * s;
    tmp[2] = (h%12)*30 + 0.5 * m + (1/200) * s;
    
    return tmp;
}

bool hsCruch(vector <double> be, vector <double> af ){
    if (be[0] < be[2] && af[0] >= af[2])
        return true;
     // 초침이 354도에서 0도로 넘어갈 때 예외 케이스
    if(be[0] == 354 && be[2] > 354)
        return true;
    return false;
}

bool msCruch(vector <double> be, vector <double> af ){
    if (be[0] < be[1] && af[0] >= af[1])
        return true;
     // 초침이 354도에서 0도로 넘어갈 때 예외 케이스
    if(be[0] == 354 && be[1] > 354)
        return true;
    return false;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int start = changeSecond(h1, m1, s1);
    int end = changeSecond(h2, m2, s2);
    int answer = 0;
    
    for (int i = start ; i < end; i++){
        vector <double> bef = getDgree(i);
        vector <double> aft = getDgree(i+1);
    
        //초침-분침 충돌 확인
        bool a = msCruch(bef, aft);
        //초침-시침 충돌 확인
        bool b = hsCruch(bef, aft);
        
         // 초침이 분침과 시침과 겹침이 발생했을 때,
        if(a && b){
            // 시침과 분침의 각도가 같다면 +1만 해줘야함
            if(aft[2] == aft[1]) 
                answer++;
            // 아니라면 +2
            else answer += 2;
        }
        // 둘 중 하나라도 겹치면 +1
        else if (a || b) 
            answer++;
    }
    
     // 위 로직은 시작시간에 대한 검사를 안해줬음
    // 그래서 0시 또는 12시에 시작한다면, 한번 겹치고 시작하는 것이기 때문에 +1
    if(start == 0 || start == 43200) 
        answer++;
    return answer;
}