//
//  짝지어제거하기_Lv2.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: 짝지어 제거하기 : Word Compression
/// MARK: - 연속으로 같은 문자열을 하나씩 제거해서 모두 제거할 수 있는지 여부를 확인해라!!!

// MARK: - 짝지어 제거하기 복습 문제풀이
#if 0
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> STK;
    for(int i=0; i<s.length(); i++) {
        if(STK.empty()) {
            STK.push(s[i]);
        } else {
            if(STK.top() == s[i]) STK.pop();
        }
    }
    
    return STK.empty() ? 1 : 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/// MARK: 복습 통과 답안; '19. 10. 12.
int solution(string s) {
    stack<char> STK;
    for(int i=0; i<s.length(); i++) {
        if(STK.empty()) STK.push(s[i]);
        else {
            if(STK.top() == s[i]) STK.pop();
            else STK.push(s[i]);
        }
    }
    return STK.empty() ? 1 : 0;
}
#endif

//int removePair(string s) {
//    stack<int> stk;
//    for(int i=0; i<s.length(); i++) {
//        if(stk.empty()) stk.push(s[i]);
//        else {
//            if(s[i]==stk.top()) stk.pop();
//            else stk.push(s[i]);
//        }
//    }
//    return (stk.empty()) ? 1 : 0;
//}
