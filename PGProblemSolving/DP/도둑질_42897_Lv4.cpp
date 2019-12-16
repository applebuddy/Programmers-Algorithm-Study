//
//  도둑질_42897_Lv4.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/27.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 도둑질 Lv4

#if 0
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> money) {
    int prev = 0;
    int twoPrev = 0;
    bool isFirst = false;
    if(money.size()==1) return money[0];
    if(money.size()==2) return max(money[0], money[1]);
    vector<int> DP(money.size(),0);
    vector<int> DP2(money.size(),0);
    
    
    for(int i=0; i<money.size()-1; i++) {
        DP[i] = max(twoPrev+money[i], prev);
        twoPrev = prev;
        prev = DP[i];
    }
    
    prev = 0;
    twoPrev = 0;
    for(int i=1; i<money.size(); i++) {
        DP2[i] = max(twoPrev+money[i], prev);
        twoPrev = prev;
        prev = DP2[i];
    }

    return max(DP2.back(),DP[DP.size()-2]);
}
#endif
