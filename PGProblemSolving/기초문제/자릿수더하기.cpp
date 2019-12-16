//
//  자릿수더하기.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 14/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 자릿수더하기 : Adding Digits
// MARK: 숫자 각 자리의 숫자를 합한 결과를 출력하라!!

#include <iostream>

using namespace std;
int addingDigits(int n)
{
    int answer = 0;
    while(n>0){
        answer+=n%10;
        n/=10;
    }
    return answer;
}
