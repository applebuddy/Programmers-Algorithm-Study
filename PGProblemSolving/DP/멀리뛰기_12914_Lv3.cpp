//
//  멀리뛰기_12914_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/25.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 멀리뛰기_12914_Lv3

#if 0
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<int> V(n+1, 0);
    V[1]=1; V[2]=2;
    if(n<3) return V[n];
    for(int i=3; i<=n; i++) V[i] = (V[i-1] + V[i-2])%1234567;
    return V[n];
}
#endif
