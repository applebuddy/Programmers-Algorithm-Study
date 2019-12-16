//
//  멀쩡한사각형.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 11/11/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 멀쩡한사각형
// * 행 별 빠진 정사각형 갯수 (/% -> 몫&나머지 계산)
// 1행 : 8/%12 -> 0 + 8(1) = 1
// 2행 : 16/%12 -> 1-0 + 4(1) = 2
// 3행 : 24/%12 -> 2-1 + 0(0) = 1
// 4행 : 32/%12 -> 2-2 + 8(1) = 1
// 5행 : 40/%12 -> 3-2 + 4(1) = 2
// 6행 : 48/%12 -> 4-3 + 0(0) = 1
// 7행 : 56/%12 -> 4-4 + 8(1) = 1
// 8행 : 64/%12 -> 5-4 + 4(1) = 2
// 9행 : 72/%12 -> 6-5 + 0(0) = 1
// 10행 : 80/%12 -> 6-6 + 8(1) = 1
// 11행 : 88/%12 -> 7-6 + 4(1) = 2
// 12행 : 96/%12 -> 8-7 + 0(0) = 1

#if 0
// GCD를 활용한 가장 효율적인 통과 답안
#include <iostream>

using namespace std;

int getGCD(const int &a, const int &b) {
    if(b==0) return a;
    return getGCD(b,a%b);
}
long long solution(int w,int h)
{
    long long W=w, H=h;
    return W*H-(w+h-getGCD(w,h));
}

// 2번째 통과 답안)
#include <iostream>
using namespace std;

long long solution(int w,int h)
{
    long long Ans = 0;
    long long quot = 0;
    long long W=w, H=h;
    for(int i=1; i<=h; i++) {
        long long num = i*W;
        long long newQuot = num/H;
        long long isRem = num%H==0 ? 0 : 1;
        Ans += newQuot - quot + isRem;
        quot = newQuot;
    }
    return W*H - Ans;
}
#endif
