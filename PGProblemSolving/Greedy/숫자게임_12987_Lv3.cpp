//
//  숫자게임_12987_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/18.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 숫자게임_12987_Lv3
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int j=0;
    for(int i=0; i<A.size();) {
        if(j>=B.size()) break;
        if(A[i]<B[j]) {
            answer++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    return answer;
}
#endif
