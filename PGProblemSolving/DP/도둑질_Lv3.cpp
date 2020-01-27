//
//  도둑질_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2020/01/27.
//  Copyright © 2020 MinKyeongTae. All rights reserved.
//

// MARK: 도둑질 Lv3

#if 0
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {

    vector<int> DP(money.size(), 0);
    vector<int> DP2(money.size(), 0);
    
    int prev = 0, pprev = 0;
    for(int i=0; i<money.size()-1; i++) {
        DP[i] = max(pprev + money[i], prev);
        pprev = prev;
        prev = DP[i];
    }
    
    prev = 0, pprev = 0;
    for(int i=1; i<money.size(); i++) {
        DP2[i] = max(pprev + money[i], prev);
        pprev = prev;
        prev = DP2[i];
    }
    
    return max(DP[money.size()-2], DP2[money.size()-1]);
}
#endif
