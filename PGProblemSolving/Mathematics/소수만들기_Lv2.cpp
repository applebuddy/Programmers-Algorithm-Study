//
//  소수만들기_Lv2.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 소수만들기
/// MARK: nums 배열에 존재하는 숫자 3개를 이용해 소수를 만드는 경우의 수를 출력하라!!
/// * nums 배열에 존재하는 숫자는 중복숫자가 존재하지 않는다.

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int MAX = 3001;

int makePrimeNumber(vector<int> nums) {
    int Ans = 0;
    vector<bool> prime(MAX,false);
    for(int i=2; i*i<=MAX; i++)
        if(prime[i]==false)
            for(int j=i+i; j<=MAX; j+=i)
                prime[j]=true;
    
    for(int i=0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            for(int k=j+1; k<nums.size(); k++) {
                if(prime[nums[i]+nums[j]+nums[k]]==false) {
                    printf("%d\n",nums[i]+nums[j]+nums[k]);
                    Ans++;
                }
            }
        }
    }
    
    return Ans;
}
