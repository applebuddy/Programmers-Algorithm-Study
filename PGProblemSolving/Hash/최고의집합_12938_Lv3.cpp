//
//  최고의집합_12938_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 13/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: 최고의집합 Lv2 12938

// MARK: - 최고의집합 복습 문제풀이
#if 0
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s) return {-1};
    while(n > 0) {
        if(s%n == 0) {
            vector<int> temp(n, s/n);
            answer.insert(answer.end(), temp.begin(), temp.end());
            break;
        }else {
            answer.push_back(s/n);
            s -= s/n;
            n--;
        }
    }
    return answer;
}
#endif

// MARK: - 최고의집합 이전 문제풀이 
#if 0
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> theBestSet(int n, int s) {
    vector<int> answer;
    int div;
    if(s<n) return {-1};
    while(n>0) {
        div=s/n;
        if(s%n==0) {
            vector<int> temp(n,div);
            answer.insert(answer.end(),temp.begin(),temp.end());
            return answer;
        }
        answer.push_back(div);
        s-=s/n;
        n--;
    }
    return answer;
}
#endif
