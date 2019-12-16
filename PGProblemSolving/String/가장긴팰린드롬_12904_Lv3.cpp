//
//  가장긴팰린드롬_12904_Lv3.cpp
//  ProgrammersAlgorithmStudy
//
//  Created by MinKyeongTae on 09/10/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - Manacher's Algorithm 적용 답안.

#if 0
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

vector<int> C(5003,0);

void manachersAlgorithm(string S) {
    int r=0,p=0;
    for(int i=0; i<(int)S.length(); i++) {
        if(i<=r) C[i]=min(C[2*p-i],r-i);
        else C[i]=0;

        while(i-C[i]-1>=0 && i+C[i]+1<S.length() && S[i-C[i]-1]==S[i+C[i]+1]) C[i]++;

        if(r<i+C[i]) {
            r=i+C[i];
            p=i;
        }
    }
}

int theLongestPelindrom(string s)
{
    int answer=0;
    string S="";
    for(int i=0; i<s.length(); i++) {
        S+='@';
        S+=s[i];
    }
    S+='@';

    manachersAlgorithm(S);
    for(int i=0; i<S.length(); i++) {
        answer = answer<C[i] ? C[i] : answer;
    }

    return answer;
}

int main() {
    int Ans = theLongestPelindrom("PPAPAPA");
    printf("%d\n",Ans);
    return 0;
}
#endif

/// MARK: 정확성 1, 효율성 1개 씩 실패답안)
#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int theLongestPelindrom2(string s)
{
    int Ans=1;
    int len = (int)s.length();
    string S = s;
    string comp = S;
    reverse(comp.begin(), comp.end());
    
    for(int i=len; i>1; i--) {
        for(int j=0; j<=s.length()-i; j++) {
            string temp = S.substr(j,i);
            if(comp.find(temp)!=string::npos) {
                Ans=i;
                break;
            }
        }
        if(Ans>1) break;
    }

    return Ans;
}
#endif
