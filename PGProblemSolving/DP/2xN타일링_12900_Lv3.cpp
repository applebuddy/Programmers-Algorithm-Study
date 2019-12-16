//
//  2xN타일링_12900_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 11/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

#if 0
#include <string>
#include <vector>

using namespace std;

int Cache[60001] = {0,};

int DP(int N) {
    if(N<=2) return N;
    if(Cache[N]>0) return Cache[N];
    return Cache[N] = (DP(N-1)+DP(N-2))%1000000007;
}

int twoNTiling(int n) {
    int answer = 0;
    answer = DP(n);
    return answer;
}
#endif
