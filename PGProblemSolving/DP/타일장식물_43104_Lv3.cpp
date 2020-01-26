//
//  타일장식물_43104_Lv3.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 07/10/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: 타일장식물_43104

// MARK: - 타일장식물 복습 풀이답안
#if 0
#include <string>
#include <vector>

using namespace std;

vector<long long> Fib(101,0);
vector<long long> Ans(101,0);

long long getFib(int N) {
    if(N<=2) return Fib[N] = 1;
    if(Fib[N]>0) return Fib[N];
    return Fib[N] = getFib(N-1) + getFib(N-2);
}

long long solution(int N) {
    if(N==1) return 1;
    long long answer = getFib(N) + getFib(N+1) + getFib(N+2);
    return answer;
}
#endif

// MARK: - 타일장식물 이전 풀이답안
#if 0
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

long long C[83] = {0,};

long long getFibonachi(int N) {
    if(N<=1) return N;
    if(C[N]>0) return C[N];
    C[N] = getFibonachi(N-1)+getFibonachi(N-2);
    return C[N];
}

int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    long long answer = 0;
    answer = (getFibonachi(N+1)+getFibonachi(N))*2;
    printf("%lld\n",answer);
    return 0;
}
#endif
