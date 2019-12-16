//
//  소수찾기_42839_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 12/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 소수찾기_42839 : Prime Searching Algorithm Problem
///  MARK: unordered_map 사용 통과답안
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int,int> UMP;

bool checkPrime(int N, string S) {
    unordered_map<int,int> MP = UMP;
    bool flag=true;
    while(N>0) {
        int temp = N%10;
        if(MP[temp]>0) MP[temp]--;
        else {
            flag=false;
            break;
        }
        N/=10;
    }
    return (flag) ? true : false;
}

int findPrimeWithMap(string numbers) {
    int Ans = 0;
    sort(numbers.begin(), numbers.end(), greater<char>());
    for(auto s: numbers) UMP[s-'0']++;
    
    int MAX = stoi(numbers);
    vector<int> C(MAX+1,true);
    for(int i=2; i*i<=MAX; i++) {
        for(int j=i+i; j<=MAX; j+=i) {
            C[j]=false;
        }
    }
    
    for(int i=2; i<=MAX; i++) if(C[i] && checkPrime(i, numbers)) Ans++;
    
    return Ans;
}

/// MARK: 순수 벡터 사용 통과 답안)
#if 0
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checkNumber(int i,string numbers) {
    bool flag = false;
    vector<bool> visit(numbers.length());
    while (i != 0) {
        flag = false;
        int temp = i % 10;
        for (int j = 0; j <= numbers.length(); j++) {
            if (temp == numbers[j]-'0'&&visit[j]==0) {
                flag = true;
                visit[j] = 1;
                break;
            }
        }
        if (flag == false)
            return false;

        i /= 10;
    }

    return true;
}

int findPrimeWithVector(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<int>());
    int maxNum = stoi(numbers.c_str());
    vector<int> check(maxNum+1,1);

    for(int i=2; i<=maxNum; i++){
        if(check[i]==1){
            for(int j = i+i; j<=maxNum; j+=i){
                check[j] = 0;
            }
        }
    }

    for(int i=2; i<=maxNum; ++i){
        if(checkNumber(i,numbers) == true){
            if(check[i]==1){
                answer++;
            }
        }
    }
    cout << answer << "\n";
    return answer;
}
#endif
