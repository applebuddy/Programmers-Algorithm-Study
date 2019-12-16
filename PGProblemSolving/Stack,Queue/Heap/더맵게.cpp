//
//  더맵게.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 14/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 더맵게
// 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
// 몇번을 반복해야 모든 음식을 K지수 이상으로 만들 수 있을까?

#include <string>
#include <vector>
#include <queue>

using namespace std;

int moreSpicy(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(auto s : scoville) q.push(s);
    
    while(q.top() < K) {
        if(q.size() == 1) return -1;
        int one = q.top();
        q.pop();
        int two = q.top();
        q.pop();
        q.push(one + two*2);
        answer++;
    }
    return answer;
}
