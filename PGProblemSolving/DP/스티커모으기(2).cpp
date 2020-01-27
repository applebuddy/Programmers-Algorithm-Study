//
//  스티커모으기(2).cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2020/01/27.
//  Copyright © 2020 MinKyeongTae. All rights reserved.
//

// MARK: 스티거모으기(2) Lv3 문제풀이

#if 0
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    if(sticker.size() == 1) return sticker[0];
    
    int prev = 0, pprev = 0;
    vector<int> DP(sticker.size(), 0);
    vector<int> DP2(sticker.size(), 0);
    for(int i=1; i<sticker.size(); i++) {
        DP[i] = max(pprev + sticker[i], prev);
        pprev = prev;
        prev = DP[i];
    }
    
    prev = 0, pprev = 0;
    for(int i=0; i<sticker.size()-1; i++) {
        DP2[i] = max(pprev + sticker[i], prev);
        pprev = prev;
        prev = DP2[i];
    }
    
    return max(DP2[DP2.size()-2], DP[DP.size()-1]);
}
#endif
