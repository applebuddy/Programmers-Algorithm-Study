//
//  거스름돈_12907_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/05.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: 거스름돈 Lv3 12907

// MARK: - 거스름돈 DP 문제풀이
#if 0
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> DP(n+1, 0);
    for(int i=0; i<=n; i++) DP[i] = i%money[0] == 0 ? 1 : 0;
    for(int i=1; i<money.size(); i++)
        for(int j=money[i]; j<=n; j++)
            DP[j] += DP[j-money[i]] % 1000000007;
    
    return DP[n];
}
#endif

// MARK: - Only 정확성 통과 답안
#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<vector<int>,int> MP;
int DFS(int idx, int sum, vector<int> &money, int &target, vector<int> ST) {
    int Ans = 0;
    if(idx >= money.size() || sum > target || MP[ST]==1) return 0;
    if(sum == target && MP[ST]==0) {
        return MP[ST] = 1;
    }
    
    ST.push_back(money[idx]);
    Ans += DFS(idx, sum+money[idx], money, target, ST) % 1000000007;
    Ans += DFS(idx+1, sum, money, target, ST) % 1000000007;
    ST.pop_back();
    return Ans;
}

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> ST;
    sort(money.begin(), money.end());
    answer = DFS(0,0,money,n,ST);
    return answer;
}
#endif
