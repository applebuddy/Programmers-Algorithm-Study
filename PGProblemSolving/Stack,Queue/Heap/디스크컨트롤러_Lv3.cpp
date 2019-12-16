//
//  디스크컨트롤러.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 17/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//
 
/// MARK: 디스크 컨트롤러_Lv3 : THE HEAP ALGORITHM PROBLEM

// MARK: - 디스크컨트롤러 힙 사용 복습 답안 '19. 12. 08.

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct CompareProcessTime {
    template <class T = vector<int>>
    bool operator() (T &a, T &b) {
        return a[1] > b[1];
    }
};

struct CompareInputTime {
    template <class T = vector<int>>
    bool operator() (T &a, T &b) {
        return a[0] < b[0];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end(), CompareInputTime());
    priority_queue<vector<int>, vector<vector<int>>, CompareProcessTime> PQ;
    vector<vector<int>>::iterator iter = jobs.begin();
    int nowTime = jobs[0][0];
    while(iter != jobs.end() || !PQ.empty()) {
        while(iter != jobs.end() && (*iter)[0] <= nowTime) {
            PQ.push(*iter++);
        }
        
        if(!PQ.empty()) {
            nowTime += PQ.top()[1];
            answer += (nowTime - PQ.top()[0]);
            PQ.pop();
        } else nowTime = (*iter)[0];
    }
    return answer/jobs.size();
}
    
#if 0
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class CompareProcessTime {
    public:
        template <class T = vector<int>>
        bool operator() (T& a, T& b) const {
            return a[1] > b[1];
        }
};

class CompareLoadingTime {
    public:
        template <class T = vector<int>>
        bool operator() (T& a, T& b) const {
            return a[0] < b[0];
        }
};

int diskController3(vector<vector<int>> jobs) {
    int Ans = 0;
    sort(jobs.begin(), jobs.end(), CompareLoadingTime());
    priority_queue<vector<int>,vector<vector<int>>,CompareProcessTime> PQ;
    int time = jobs[0][0];
    auto iter = jobs.begin();
    // 만약 작업해야할 게 존재하면,
    while(iter != jobs.end() || !PQ.empty()) {
        // 현재 작업하는 시간이전에 시작 가능한 작업을 큐에 전부 추가해준다.
        while(iter != jobs.end() && (*iter)[0] <= time) {
            PQ.push(*iter++);
        }
        
        /// 큐에 작업이 존재하면,
        if(!PQ.empty()) {
            // 큐의 가장 적절한 작업을 처리하고,
            time += PQ.top()[1];
            
            // 실질적인 작업시간을 누적합 처리한다.
            Ans += time - PQ.top()[0];
            
            // 작업한 것은 큐에서 제거한다.
            PQ.pop();
        } else {
            // 시간은 다음 작업 큐의 시작시간으로 설정한다. 
            time = (*iter)[0];
        }
    }
    return Ans/jobs.size();
}
#endif
    
////// MARK: - 통과 답안2) 조수환님 답안 -> 이해 + 공부 필요 ㅠ.ㅠ
//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//
//class CompareProcessTime {
//    public :
//    template <class T = vector<int>>
//    bool operator () (T& a, T& b) const {
//        return a[1] > b[1];
//    }
//};
//
//class CompareInputTime {
//    public :
//    template <class T = vector<int>>
//    bool operator() (T& a, T& b) const {
//        return a[0] < b[0];
//    }
//};
//
//int diskController(vector<vector<int>> jobs) {
//    int answer = 0;
//
//    priority_queue<vector<int>, vector<vector<int>>, CompareProcessTime> PQ;
//    sort(jobs.begin(), jobs.end(), CompareInputTime());
//
//    int time = jobs[0][0];
//    auto iter = jobs.begin();
//
//    while(iter != jobs.end() || !PQ.empty()) { // 디스크의 순회가 끝나지 않았고 + PQ에 작업데이터가 존재한다면,
//        while(iter!=jobs.end() && (*iter)[0]<=time) {
//            PQ.push(*iter++); // 도착해 있는 작업들을 모두 priority_queue에 넣는다.
//        }
//
//        // priority_queue 내 처리할 데이터가 존재한다면,
//        if(!PQ.empty()) {
//            time += PQ.top()[1];
//            answer += time - PQ.top()[0];
//            PQ.pop();
//        } else {
//            time = (*iter)[0]; // 다음 수행할 작업의 대기시간으로 초기화
//        }
//    }
//
//    answer /= jobs.size();
//    return answer;
//}

//int main() {
//    // 예제 테스트 실행 -> 9 출력
//    printf("%d\n",diskController({{0, 3}, {1, 9}, {2, 6}}));
//    return 0;
//}

//// MARK: - 통과 답안1) 자력으로 풀지 못함... 복습 필요 ㅠ.ㅠ
//#include <string>
//#include <vector>
//#include <iostream>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//struct Comapre_pq {
//    bool operator()(vector<int> a, vector<int> b) {
//        return a[1] > b[1];
//    }
//};
//
//bool Compare(vector<int> a, vector<int> b) {
//    return a[0] < b[0];
//}
//
//
//int solution(vector<vector<int>> jobs) {
//    priority_queue<vector<int>, vector<vector<int>>, Comapre_pq> temp;
//    sort(jobs.begin(), jobs.end(), Compare);
//    vector<int> temp1;
//    int total = 0; // 총 소요시간
//    int work = 0;    //현재 수행한 작업
//    int need_work = 0;   //해야할 작업
//    int i = 0; // 디스트 작업 얼마나 처리했는지 지표로 삼는 인덱스
//    while (1) {
//        while (i!=jobs.size()) {
//            if (jobs[i][0] == work)
//            {
//                temp.push(jobs[i]);
//                i++;
//            }
//            else break;
//        }
//
//        // 만약 해야할 작업이 하나도 없고, temp에 값이 존재하면(작업할 디스크가 존재하면)
//        if (need_work <= 0 && !temp.empty())
//        {
//            // 현재 작업할 데이터를 불러온다.
//            temp1 = temp.top();
//            temp.pop();
//            // 현재 작업할 디스크의 작업 소요를 need_work에 담는다.
//            need_work = temp1[1];
//            // 전체 작업량에 현재 작업량을 누적시킨다.
//            total += temp1[1];
//        }
//
//        // total에 temp.size()를 더한다. (* temp 사이즈를 더하는 이유는??)
//        total += temp.size();
//
//        // 필요한 작업량을 1씩 감소시킨다.
//        need_work--;
//        // 필요한 작업량이 줄어드는 만큼 현재까지 작업한 시간을 누적한다.
//        work++;
//
//        // 만약 작업할 디스크가 더이상 없고, 필요한 작업량이 없고, i인덱스로 모든 일들을 탐색했다면 작업을 종료한다.
//        if (temp.empty() && need_work == 0 && i == jobs.size()) {
//            break;
//        }
//    }
//    // 전체 디스크의 작업량 / 디스크 갯수 -> 평균소요시간 계산
//    return total / jobs.size();
//}
//


/// MARK: - 기본 테스트케이스만 통과, 그 실제테스트 1개 빼고 전부 Failed
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//typedef pair<int,int> Pair;
//

//struct Compare {
//    bool operator()(Pair p1, Pair p2) {
//        if(p1.second - p1.first > p2.second - p2.first) return true;
//        else return false;
//    }
//};

//int diskController(vector<vector<int>> jobs) {
//    if(jobs.size()==1) return jobs[0][0]+jobs[0][1];
//    priority_queue<Pair, vector<Pair>, Compare> pq;
//    for(auto v : jobs) {
//        pq.push(make_pair(v[0],v[1]));
//    }
//    int sum = pq.top().first + pq.top().second;
//    int subSum = pq.top().first + pq.top().second;
//    int prev = pq.top().first + pq.top().second;
//    int now = 0;
//    pq.pop();
//    while(!pq.empty()) {
//        Pair p = pq.top();
//        now = prev-p.first+p.second;
//        subSum += p.second;
//        sum += now;
//        prev = subSum;
//        pq.pop();
//    }
//    printf("%d",sum);
//    return sum/int(jobs.size());
//}
