//
//  다리를 지나는 트럭_42583.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 07/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: 다리를 지나는 트럭 복습 답안; '19. 10. 11.
#if 0
#include <string>
#include <vector>
#include <queue>

using namespace std;

int theTruckPassingBridge(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    queue<int> Q;
    int idx=0;
    while(idx<truck_weights.size()) {
        if(Q.size()==bridge_length) {
            sum -= Q.front();
            Q.pop();
        } else {
            if(weight >= sum+truck_weights[idx]) {
                sum += truck_weights[idx];
                Q.push(truck_weights[idx]);
                idx++;
                answer++;
            } else {
                Q.push(0);
                answer++;
            }
        }
    }
    return answer+bridge_length;
}
#endif

//#include <stdio.h>
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int TrucksPassingBridge(int bridge_length, int weight, vector<int> truck_weights) {
//    int sum=0;
//    int time=0;
//    queue<int> q;
//    for(int i=0; i<truck_weights.size(); i++){
//        int w = truck_weights[i];
//
//        while(1){
//            // 1)큐가 비었을경우, 2)안비었을경우(무게감당이된다/안된다.), 3)꽉찼을경우(맨뒤큐를빼줌)
//            if(q.empty()){
//                q.push(w);
//                sum+=w;
//                time++; // 시간은 소요된다.
//                break; // 다음 트럭을 비교하기위해 빠져나간다.
//
//            }else if(q.size() == bridge_length){
//                sum -= q.front();
//                q.pop();
//
//            }else{
//                // 무게감당이 된다/안된다.
//                if(sum+w <= weight){ // 무게감당이 된다면?
//                    q.push(w); //트럭을 추가하고,
//                    sum+=w;
//                    time++; // 시간은 소요된다.
//                    break; // 다음 트럭을 비교한다.
//                }else{ // 무게감당이 안된다면? 공값을 큐에 넣는다.
//                    q.push(0);
//                    time++; // 시간은 소요된다.
//                }
//
//            }
//        }
//    }
//    return time+bridge_length;
//}
