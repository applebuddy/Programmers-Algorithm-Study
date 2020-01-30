//
//  단속카메라_42884.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 09/11/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: 단속카메라 Lv3 42884 : Greedy Problem

// MARK: - 단속카메라 복습 문제풀이
#if 0
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    });
    
    int target = routes[0][1];
    for(int i=1; i<routes.size(); i++) {
        if(target < routes[i][0]) {
            answer++;
            target = routes[i][1];
        }
    }
    return answer;
}
#endif

// MARK: - 단속카메라 문제풀이
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
    });
    
    int temp = -30001;
    for(int i=0; i<routes.size(); i++) {
        if(routes[i][0] > temp) {
            temp = routes[i][1];
            answer++;
        }
    }
    return answer;
}

// -18 -13
//   -14 -5
//     -5 -3
//       -20 15
#endif

#if 0
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(),routes.end());
    vector<int> temp = routes[0];
    int answer=1;
    for(int i=0; i<routes.size(); i++) {
        if(temp[1] > routes[i][1]) temp = routes[i];
        if(temp[1] < routes[i][0]) {
            answer++;
            temp = routes[i];
        }
    }
    return answer;
}
#endif
