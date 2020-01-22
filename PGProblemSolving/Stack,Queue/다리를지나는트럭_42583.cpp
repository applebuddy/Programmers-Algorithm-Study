//
//  다리를 지나는 트럭_42583.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 07/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: 다리를지나는트럭 풀이답안
#if 0
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time=0, total=0, idx=0;
    queue<int> Q;
    
    while(idx < truck_weights.size()) {
        if(total+truck_weights[idx] <= weight) {
            Q.push(truck_weights[idx]);
            total+=truck_weights[idx];
            idx++;
        } else Q.push(0);
        
        if(Q.size() >= bridge_length) {
            total-=Q.front();
            Q.pop();
        }
        time++;
    }
    return time + bridge_length;
}
#endif
