//
//  입국심사_43238_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 10/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: 입국심사_43238_Lv3 : Binary Search Problem

// MARK: - 입국심사 복습 문제풀이
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 0, max = 0, right = 0;
    for(auto &v: times) max = max < v ? v : max;
    right = max * n;
    
    long long answer = right;
    long long mid = 0;
    while(left <= right) {
        mid = (left + right) / 2;
        long long tot = 0;
        for(auto &v: times) tot += mid/v;
        if(tot < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
            answer = answer > mid ? mid : answer;
        }
    }
    
    return answer;
}
#endif

#if 0
#include <string>
#include <vector>

using namespace std;

long long enteringJudge(int n, vector<int> times) {
    long long left=1, right=0, max=0, tot=0, mid=0, answer=0;
    for(auto v: times) max = max<v ? v : max;
    right=n*max;
    answer=right;
    
    while(left <= right) {
        tot=0;
        mid=(left+right)/2;
        
        for(auto v: times) tot+=mid/v;
        
        if(tot < n) left=mid+1;
        else {
            if(answer > mid) answer = mid;
            right=mid-1;
        }
    }
    return answer;
}

int main() {
    enteringJudge(3, {2,3,4});
    return 0;
}
#endif
