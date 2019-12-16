//
//  점프와순간이동_12980_Lv2.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 08/10/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 점프와 순간이동_12980_Lv2

#include <iostream>
using namespace std;

int jumpAndTeleport(int n) {
    int Ans=0;
    while(n>0) {
        if(n%2==0) n/=2;
        else {
            n--;
            Ans++;
        }
    }
    return Ans;
}
