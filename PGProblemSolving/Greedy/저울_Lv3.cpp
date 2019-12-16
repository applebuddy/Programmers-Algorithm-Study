//
//  저울_Lv3.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 21/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 저울
/// MARK: 저울이 있다. 왼쪽에는 특정 물건의 무게를, 좌측에는 추 만을 얹어놓을 수 있다. 해당 추들(무게 배열, weight)로 잴 수 없는 최소의 무게를 구해라!!

// 통과답안, Compact Ver. '19. 10. 12
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int theScale(vector<int> weight) {
    int answer = 0;
    sort(weight.begin(), weight.end());
    int sum=0;
    sum+=weight[0];
    for(int i=1; i<weight.size(); i++) {
        if(sum+1 < weight[i]) return sum+1;
        sum+=weight[i];
    }
    return sum+1;
}
#endif

// 통과답안, Compact Ver. '19. 09. 21
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<int> weight) {
//    int answer;
//    sort(weight.begin(), weight.end());
//    if(weight[0]>1) return weight[0]-1;
//
//    int sum = weight[0];
//    for(int i=1; i<weight.size(); i++) {
//        if(sum+1 < weight[i]) return sum+1;
//        else sum+=weight[i];
//        if(i==weight.size()-1) {
//            sum++;
//            break;
//        }
//    }
//    answer = sum;
//    return answer;
//}


///// 통과답안 '19. 09. 21.
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Compare {
//public:
//    template <class T = int>
//    bool operator() (T& a, T& b) const {
//        return a < b;
//    }
//};
//
//int weightScale(vector<int> weight) {
//    int answer = 0;
//    sort(weight.begin(), weight.end(), Compare());
//    if(weight[0] > 1) return weight[0]-1;
//
//    int sum = weight[0];
//    for(int i=1; i<weight.size(); i++) {
//        if(sum < weight[i] && sum+1 != weight[i]) {
//            answer = sum+1;
//            break;
//        } else {
//            sum += weight[i];
//            if(i == weight.size()-1) {
//                answer = sum+1;
//                break;
//            }
//        }
//    }
//
//    return answer;
//}
