//
//  징검다리_43236_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/10.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 징검다리 Lv3

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int theSteppingStone(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    if(rocks.back() != distance) rocks.push_back(distance);
    int left = 1, right = distance;

    while(left <= right) {
        int mid = (left + right) / 2;
        int diff = 0, removed = 0;
        for(int i=0; i<rocks.size(); i++) {
            if(rocks[i] - diff < mid) {
                removed++;
            } else diff = rocks[i];
        }

        if(removed > n) right = mid-1;
        else {
            answer = answer < mid ? mid : answer;
            left = mid+1;
        }
    }
    return answer;
}
