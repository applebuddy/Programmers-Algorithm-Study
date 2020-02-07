//
//  등굣길_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2020/02/08.
//  Copyright © 2020 MinKyeongTae. All rights reserved.
//

// MARK: 등굣길 Lv3
// MARK: - DP 문제풀이
#if 0
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<ll>> Map(101, vector<ll>(101,0));
    vector<vector<ll>> DP = Map;
    DP[0][1] = 1;
    
    for(auto &v: puddles) Map[v[1]][v[0]] = -1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(Map[i][j]==-1) DP[i][j] = 0;
            else DP[i][j] = (DP[i-1][j] + DP[i][j-1]) % 1000000007;
        }
    }

    return (int)DP[n][m];
}
#endif
