//
//  숫자게임_12987_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/18.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: 숫자게임 Lv3 12987

// MARK: - 숫자게임 복습 풀이답안
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int idxA = 0, idxB = 0;
    while(idxA < A.size() && idxB < B.size()) {
        if(A[idxA] < B[idxB]) {
            answer++;
            idxA++;
        }
        idxB++;
    }
    return answer;
}
#endif

// MARK: - 이전 풀이답안
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
