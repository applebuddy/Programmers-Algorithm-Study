//
//  거스름돈_12907_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/05.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

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
