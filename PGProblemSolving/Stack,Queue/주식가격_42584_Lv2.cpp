//
//  주식가격_42584.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 07/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: 주식가격 Lv2 문제풀이
/// MARK: - 가격이 들어간 배열의 각 인덱스 별 i초를 의미한다. 각 인덱 스 별 해당 가격 이상의 가격이 유지되는 시간을 출력해라.

#if 0
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer((int)prices.size(),0);
    for(int i=0; i<prices.size()-1; i++) {
        for(int j=i; j<prices.size()-1; j++) {
            if(prices[i] <= prices[j]) answer[i]++;
            else break;
        }
    }
    return answer;
}
#endif
