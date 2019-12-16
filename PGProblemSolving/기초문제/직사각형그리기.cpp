//
//  직사각형그리기.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 직가각형 그리기
/// MARK: 가로 n, 세로 m 길이의 직사각형을 그려라!!

#include <iostream>

using namespace std;

int drawRect(void) {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int a;
    int b;
    cin >> a >> b;
    
    for(int i=0; i<b; i++) {
        for(int j=0; j<a; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
