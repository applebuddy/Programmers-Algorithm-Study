//
//  괄호변환_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 11/11/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 괄호변환_Lv2
#if 0
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool checkBrace(string S) {
    stack<char> STK;
    for(int i=0; i<S.length(); i++) {
        if(S[i]=='(') STK.push(S[i]);
        else {
            if(STK.empty()) return false;
            STK.pop();
        }
    }
    if(STK.empty()) return true;
    else return false;
}

string solution(string p) {
    string answer = "";
    string U="", V="";
    if(checkBrace(p) || p=="") return p;

    int leftCount=0, rightCount=0;
    for(int i=0; i<p.length(); i++) {
        if(p[i]=='(') leftCount++;
        else rightCount++;
        if(leftCount == rightCount) break;
    }

    U = p.substr(0,leftCount+rightCount);
    V = p.substr(leftCount+rightCount,p.length()-(leftCount+rightCount));

    if(checkBrace(U)) {
        answer+=U;
        answer+=solution(V);
    } else {
        answer+="(";
        answer+=solution(V);
        answer+=")";
        U = U.substr(1,U.length()-2);
        for(int i=0; i<U.length(); i++) U[i] = U[i]=='(' ? ')' : '(';
        answer+=U;
    }
    return answer;
}
#endif
