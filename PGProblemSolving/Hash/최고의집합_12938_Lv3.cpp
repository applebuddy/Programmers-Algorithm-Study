//
//  최고의집합_12938_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 13/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 최고의집합_12938_Lv3

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
