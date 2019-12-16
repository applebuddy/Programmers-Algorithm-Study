//
//  징검다리_43236_Lv4.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/02.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(distance);
    rocks.push_back(0);
    sort(rocks.begin(), rocks.end());
    vector<int> sumV(rocks.size()+1, 0);
    for(int i=1; i<rocks.size(); i++) {
        sumV[i] = sumV[i-1] + rocks[i-1];
    }
    
    for(int i=0; i<rocks.size()-n; i++) {
        
    }
    return answer;
}
