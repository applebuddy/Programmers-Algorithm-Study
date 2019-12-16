//
//  N개의최소공배수.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - N개의 최소공배수
/// MARK: [Int] 배열, arr이 주어진다. arr의 숫자 전체에 대한 최소공배수(LCD)를 반환하라!!!

#include <string>
#include <vector>

using namespace std;

int getGCD(const int &a, const int &b) {
    if(b==0) return a;
    return getGCD(b,a%b);
}

int getLCD(int a, int b) {
    return a*b/getGCD(a,b);
}

int getLCDs(vector<int> arr) {
    int answer = arr[0];
    for(int i=1; i<arr.size(); i++) {
        answer = getLCD(answer,arr[i]);
    }
    return answer;
}
