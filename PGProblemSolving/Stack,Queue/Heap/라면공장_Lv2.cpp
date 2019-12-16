//
//  라면공장_Lv2.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 22/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

#include <string>
#include <vector>
#include <queue>

using namespace std;

/// MARK: 라면공장 복습 답안)

int noodleFactory2(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> PQ;
    int idx=0;
    for(int i=0; i<k; i++) {
        if(i==dates[idx]) PQ.push(supplies[idx++]);
        if(stock==0) {
            stock+=PQ.top();
            PQ.pop();
            answer++;
        }
        stock--;
    }
    return answer;
}

//int noodleFactory(int stock, vector<int> dates, vector<int> supplies, int k) {
//    int Ans = 0;
//
//    /// 우선순위큐 top이 항상 최댓값이 되는 MAX힙
//    priority_queue<int, vector<int>, less<int>> PQ;
//
//    /// 현재 supplies 받기를 대기중인 인덱스
//    int cnt = 0;
//
//    /// k-1 까지만 신경쓰면되고 k일부터는 보급을 받는다.
//    for(int i=0; i<k; i++) {
//        /// 만약 cnt가 dates 컨테이너 사이즈를 초과하지 않고, 현재 공급날에 도달했으면,
//        /// AND 연산등을 할때 앞쪽이 false면 해당 단락은 바로 스킵
//        /// * 단락평가 : short-circuit evaluation
//        if(cnt < dates.size() && dates[cnt]==i) {
//            /// 공급날에 맞는 공급을 받는다. (우선순위큐에 추가)
//            PQ.push(supplies[cnt]);
//            /// 공급 1회 받을때마다 카운팅
//            cnt++;
//        }
//
//        /// 만약 재고가 없게되면, 현재 공급받은 물자 중 가장 큰 공급물로 공급한다.
//        if(stock == 0) {
//            stock += PQ.top();
//            /// 공급받은 물자는 빼낸다. (우선순위 큐 pop())
//            PQ.pop();
//            /// 공급 1회 받을 때마다 공급횟수(정답) 증가
//            Ans++;
//        }
//
//        /// 재고량은 첫날부터 소모된다. 재고량이 -가 될일은 없다. 밀가루가 바닥나는 경우는 주어지지 않기 떄문이다.
//        stock--;
//    }
//    return Ans;
//}
