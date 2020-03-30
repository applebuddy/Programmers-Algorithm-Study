//
//  최소공배수와최대공약수_Lv1.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 최소공배수와 최대공약수
/// MARK: N,M의 최소공배수와 최대공약수를 구해라!!

#include <string>
#include <vector>

using namespace std;

int getGCD(int a, int b) {
    if(b==0) return a;
    return getGCD(b, a%b);
}

int getLCD(const int &a, const int &b) {
    return a*b/getGCD(a,b);
}

vector<int> GCDnLCD(int n, int m) {
    vector<int> answer;
    answer.push_back(getGCD(n,m));
    answer.push_back(getLCD(n,m));
    return answer;
}
