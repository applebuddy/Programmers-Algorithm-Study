//
//  숫자의표현_Lv2.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 숫자의 표현
/// MARK: 연속된 숫자의 합으로 n을 만들 수 있는 경우의 수를 출력해라!!!

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int expressionOfNumber(int n) {
    int Ans = 0;
    for(int i=1; i<=n/2; i++) {
        int sum = i;
        for(int j=i+1; j<n; j++) {
            sum += j;
            if(sum > n) {
                break;
            } else if(sum == n) {
                Ans++;
                break;
            }
        }
    }
    return Ans+1;
}
