//
//  N으로표현_42895_Lv3.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 07/10/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - N으로 표현_42895
#if 0
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Ans = -1;
void DFS(int N, int G, int CNT, int SUM) {
    printf("CNT:%d, SUM:%d\n",CNT,SUM);
    if(CNT>8) return;
    else if(SUM==G) {
        if(Ans==-1) Ans = CNT;
        else if(Ans > CNT) Ans = CNT;
        return;
    }
    
    int n = 0;
    for(int i=0; i<8; i++) {
        n = 10*n + N;
        DFS(N,G,CNT+i+1,SUM+n);
        DFS(N,G,CNT+i+1,SUM-n);
        DFS(N,G,CNT+i+1,SUM*n);
        DFS(N,G,CNT+i+1,SUM/n);
    }
    return;
}

int expressionOfN(int N, int number) {
    DFS(N,number,0,0);
    printf("%d\n",Ans>8 ? -1 : Ans);
    return Ans;
}

int main() {
    expressionOfN(5,12);
    return 0;
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
