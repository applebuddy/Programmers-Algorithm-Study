//
//  쇠막대기_42585.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 07/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 쇠막대기 : Stack Algorithm Problem
/// MARK: 여러 개의 쇠막대기를 레이저로 절단하려고 합니다. 효율적인 작업을 위해서 쇠막대기를 아래에서 위로 겹쳐 놓고, 레이저를 위에서 수직으로 발사하여 쇠막대기들을 자릅니다. 쇠막대기와 레이저의 배치는 다음 조건을 만족합니다.
//  쇠막대기 레이저 발사시점 -> '(' 레이저 발사 ')'
//    - 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있습니다.
//    - 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되, 끝점은 겹치지 않도록 놓습니다.
//    - 각 쇠막대기를 자르는 레이저는 적어도 하나 존재합니다.
//    - 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않습니다.

/// MARK: 통과답안 복습; '19. 10. 11.
#if 0
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> STK;
    STK.push('(');
    for(int i=1; i<arrangement.length(); i++) {
        if(arrangement[i]=='(') {
            STK.push(arrangement[i]);
        } else {
            STK.pop();
            if(arrangement[i-1]=='(') {
            answer += STK.size();
            } else if(arrangement[i-1]==')') answer++;

        }
    }
    return answer;
}
#endif

///// MARK: 통과답안 '19. 09. 19.
//#include <string>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int solution(string arrangement) {
//    int Ans = 0;
//    stack<char> stk;
//    for(int i=0; i<arrangement.length(); i++) {
//        if(arrangement[i] == '(') {
//            stk.push(arrangement[i]);
//        } else {
//            if(!stk.empty()) {
//                stk.pop();
//                if(i!=0 && arrangement[i-1]==')') Ans++;
//                else { Ans += stk.size(); }
//            }
//        }
//    }
//    return Ans;
//}


/// MARK: 통과답안 '19. 05...
//#include <stdio.h>
//#include <string>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int solution(string arrangement) {
//    stack<char> stk;
//    int answer = 0;
//    string s = arrangement;
//    stk.push('(');
//
//    for(int i=1; i<s.length(); i++){
//        char top = s[i-1];
//
//        if(top == '('){
//            if(s[i]=='('){
//                stk.push('(');
//            }else{
//                stk.pop();
//                answer+=stk.size();
//            }
//
//        }else{ // 스택 top이 ')'일때
//            if(s[i]=='('){
//                stk.push('(');
//            }else{
//                stk.pop();
//                answer++;
//            }
//        }
//    }
//
//    return answer;
//}
