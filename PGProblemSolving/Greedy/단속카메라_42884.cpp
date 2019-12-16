//
//  단속카메라_42884.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 09/11/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 단속카메라_42884 : Greedy Problem
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
