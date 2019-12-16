//
//  문자열압축_60057_Lv5.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 08/10/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 문자열압축_60057_Lv2
#if 0
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool checkEqualAlpha(string S) {
    if(S.length()==1) return true;
    else if(S.length()==2) return S[0]==S[1];
    for(int i=0; i<S.length()-1; i++) {
        if(S[i]!=S[i+1]) return false;
    }
    return true;
}

int solution(string s) {
    int answer = s.length();
    int startIdx = 1;
    
    if(checkEqualAlpha(s)) startIdx = 2;

    for(int i=startIdx; i<=s.length()/2; i++) {
        stack<string> STK;
        string temp = s;
        int Ans = 0;
        int cnt=0;
        while(1) {
            string word = temp.substr(0,i);
            if(temp.length() < i) {
                if(cnt>0) Ans+=to_string(cnt).length();
                STK.push(temp);
                break;
            } else {
                if(!STK.empty()) {
                    if(word == STK.top()) cnt = cnt==0 ? 2 : cnt+1;
                    else {
                        if(cnt>0) Ans+=to_string(cnt).length();
                        STK.push(word);
                        cnt=0;
                    }
                } else STK.push(word);
            }
            temp = temp.substr(i);
        }
        
        while(!STK.empty()) {
            Ans += STK.top().length();
            STK.pop();
        }
        answer = answer>Ans ? Ans : answer;
    }
    return answer;
}
#endif
