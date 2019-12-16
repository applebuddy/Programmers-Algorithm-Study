//
//  H-Index.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 10/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - H-Index 

#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/// MARK: 좀 더 간결한 답안
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int i=0; i<citations.size(); i++) {
        int H = citations[i];
        if(H >= citations.size()-i) return citations.size()-i;
    }
    return answer;
}
#endif

//#include <string>
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<int> citations) {
//    int answer = 0;
//    int h = 0;
//    sort(citations.begin(),citations.end(),greater<int>()); // 내림차순 정렬을 먼저한다.
//    while(1){
//        int notated=0;
//        for(int i=0; i<citations.size(); i++){
//            if(h<=citations[i]){
//                notated++;
//            }
//        }
//
//        if(h>notated || h<citations.size()-notated){
//            h--;
//            break;
//        }else{
//            h++;
//            cout << h;
//        }
//    }
//    answer = h;
//    return answer;
//}
