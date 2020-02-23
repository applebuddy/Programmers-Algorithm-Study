//
//  N으로표현_42895_Lv3.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 07/10/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - N으로 표현_42895
#if 0
#include <string>
#include <vector>

using namespace std;

int answer = -1;

void DFS(int idx, int sum, const int &N, const int &target) {
    if(idx > 8) return;
    else if(idx == 8 && sum != target) return;
    else if(sum == target) {
        if(answer == -1) answer = idx;
        else answer = answer > idx ? idx : answer;
        return;
    }

    int newN = 0;
    for(int i=0; i<8; i++) {
        newN = newN * 10 + N;
        DFS(idx+1+i, sum+newN, N, target);
        DFS(idx+1+i, sum-newN, N, target);
        DFS(idx+1+i, sum*newN, N, target);
        DFS(idx+1+i, sum/newN, N, target);
    }
}

int solution(int N, int number) {
    DFS(0, 0, N, number);
    return answer;
}
#endif

/// MARK: - N으로 표현 복습) '19. 10. 26.
#if 0
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int Ans = -1;

void DFS(int N, int number, int count, int sum) {
    if(count>8) return;
    if(sum==number) {
        if(Ans==-1) Ans=count;
        else Ans = Ans>count ? count : Ans;
        return;
    }
    
    int num = 0;
    for(int i=0; i<8; i++) {
        num = num*10+N;
        DFS(N,number,count+1+i,sum+num);
        DFS(N,number,count+1+i,sum-num);
        DFS(N,number,count+1+i,sum*num);
        DFS(N,number,count+1+i,sum/num);
    }
    return;
}

int solution(int N, int number) {
    DFS(N,number,0,0);
    return Ans;
}
#endif
