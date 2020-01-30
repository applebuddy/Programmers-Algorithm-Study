//
//  줄서는방법_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2020/01/30.
//  Copyright © 2020 MinKyeongTae. All rights reserved.
//

// MARK: 줄서는방법 Lv3

// MARK: - 줄서는방법 풀이답안
#if 0
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> FAC(21, 1);

vector<int> solution(int n, ll k) {
    vector<int> answer;
    vector<int> element;
    for(int i=1; i<=20; i++) {
        if(i<=n) element.push_back(i);
        FAC[i] = FAC[i-1] * i;
    }
    
    k--;
    for(int i=n-1; i>=1; i--) {
        ll fac = FAC[i];
        ll idx = k / fac;
        answer.push_back(element[idx]);
        element.erase(element.begin() + idx);
        k %= fac;
    }
    answer.push_back(element.back());
    
    return answer;
}
#endif
