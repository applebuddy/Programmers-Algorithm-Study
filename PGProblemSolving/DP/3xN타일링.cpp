//
//  3xN타일링.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 20/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: 3xN Tiling Problem : DP
#if 0
#include <string>
#include <vector>

using namespace std;

vector<long long> DP(5001,0);
int _3xN_Tiling(int n) {
    DP[0] = 1;
    DP[2] = 3;
    for(int i=2; i<=n; i+=2) {
        DP[i] = (DP[i-2] * 3);
        for(int j=i-4; j>=0; j-=2) {
            DP[i] += DP[j]*2;
        }
        DP[i] %= 1000000007;
    }
    
    return int(DP[n]);
}
#endif
