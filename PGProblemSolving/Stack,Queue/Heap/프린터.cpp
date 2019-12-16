//
//  프린터.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 13/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 프린터 : Heap Problem

#include <string>
#include <vector>
#include <queue>

using namespace std;

int printer(vector<int> priorities, int location) {
    priority_queue<int, vector<int>, less<int>> q;
    int Ans = 0;
    for(auto p : priorities) {
        q.push(p);
    }
    
    int idx = 0;
    int cnt = 1;
    while(!q.empty()) {
        if(priorities[idx] == q.top()) {
            q.pop();
            
            if(idx == location) {
                Ans = cnt;
                break;
            }
            cnt++;
        }
        if(idx==priorities.size()-1) idx = 0;
        else idx++;
    }
    return Ans;
}

/// MARK: pair, queue, priority_queue 사용 답안 (코드가 좀 지저분함) '19. 10. 11.
//#include <string>
//#include <vector>
//#include <queue>
//using namespace std;
//
//typedef pair<int,int> Pair;
//int solution(vector<int> priorities, int location) {
//    int answer=0;
//    queue<Pair> Q;
//    priority_queue<int> PQ;
//
//    for(int i=0; i<priorities.size(); i++) {
//        Q.push({i,priorities[i]});
//        PQ.push(priorities[i]);
//    }
//
//    while(!Q.empty()) {
//        Pair nowQueue = Q.front();
//        int prior = PQ.top();
//        /// 우선순위의 작업이 도착했을때
//        if(nowQueue.second==prior) {
//            /// 작업을 처리하고
//            answer++;
//            /// 만약 찾았던 위치면 해당 순서를 답안 제출한다.
//            if(location==nowQueue.first) break;
//            PQ.pop();
//            Q.pop();
//        } else {
//            Q.pop();
//            Q.push(nowQueue);
//        }
//    }
//
//    return answer;
//}

///// MARK: Old Solution
//
//#include <string>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int printer_old(vector<int> priorities, int location) {
//    int answer = 1;
//    queue<pair<int,int>> q;
//    priority_queue<int, vector<int>, less<int>> pq;
//
//    for(int i=0; i<priorities.size(); i++){
//        q.push(make_pair(i,priorities[i]));
//        pq.push(priorities[i]);
//    }
//
//    while(!q.empty()){
//        int index = q.front().first;  // 현재 큐의 인덱스 값과 중요도값을 저장한다.
//        int top = q.front().second;
//
//        q.pop();  // 현재 큐는
//        if(top == pq.top()){   // 현재 빠질 수 있는 큐의 우선순위가 최고일때
//            if(location==index) return answer; // 해당 위치가 문제에서 요구하는 인덱스이면 현재 출력순서를 반환
//            else {
//                pq.pop();  // 아직 요구하는 인덱스가 아니라면, 우선순위큐를 pop 시킨 뒤, 출력 수를 증가시킨다.
//                answer++;
//            }
//        }else{
//            q.push(make_pair(index,top));
//        }
//
//
//
//    }
//    return answer;
//}
