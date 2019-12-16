//
//  n진수게임_Kakao_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/17.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - n진수게임_Kakao_Lv2
#if 0
#include <string>
#include <vector>

using namespace std;

string convertNum(int N, const int &R) {
    if(N==0) return "0";
    string numStr="";
    while(N>0) {
        char str = ' ';
        int temp = N%R;
        if(temp>=10) str = char('A' + (temp-10));
        else str = char(temp + '0');
        numStr = str + numStr;
        N/=R;
    }
    return numStr;
}

string solution(int n, int t, int m, int p) {
    string idxStr = "";
    string Ans = "";
    
    for(int i=0; i<t*m; i++) {
        idxStr += convertNum(i,n);
    }

    int idx=p-1;
    for(int i=p-1; i<t*m; i+=m) {
        Ans += idxStr[idx];
        idx+=m;
    }
    
    return Ans;
}
#endif
