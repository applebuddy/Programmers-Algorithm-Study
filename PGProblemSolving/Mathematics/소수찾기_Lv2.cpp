//
//  소수찾기_2단계.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 17/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: 소수찾기 Lv2 
// MARK: - Map 사용 풀이답안
#if 0
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef unordered_map<int,int> UMap;

vector<int> Prime(10000000,1);

bool checkPrime(int N, UMap MP) {
    while(N>0) {
        int temp = N%10;
        if(MP[temp]<=0) return false;
        else MP[temp]--;
        N/=10;
    }
    return true;
}

int solution(string numbers) {
    sort(numbers.begin(), numbers.end(), greater<char>());
    int answer = 0;
    UMap MP;
    int MAX = stoi(numbers);
    
    for(int i=0; i<numbers.length(); i++) MP[numbers[i]-'0']++;
    
    for(int i=2; i<=sqrt(MAX); i++) {
        if(Prime[i]==1)
            for(int j=i+i; j<=MAX; j+=i) {
                Prime[j] = 0;
            }
    }
    
    for(int i=2; i<=MAX; i++) {
        if(Prime[i]==1 && checkPrime(i, MP)) answer++;
    }
    
    return answer;
}
#endif

// MARK: - Map 미사용 풀이답안
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int i, const string &s) {
    int num=0;
    bool flag = false;
    vector<bool> chk(s.length(),false);
    while(i>0) {
        flag = false;
        num = i%10;
        for(int i=0; i<s.length(); i++) {
            if(num == s[i]-'0' && chk[i] != true) {
                flag = true;
                chk[i] = true;
                break;
            }
        }
        if(flag == false) return false;
        i/=10;
    }
    return true;
}


int findSpecificPrimeNumber(string numbers) {
    int Ans = 0;
    sort(numbers.begin(), numbers.end(), greater<char>());
    int MAX = stoi(numbers);
    vector<bool> v(MAX+1,false);
    
    /// 1) 에라토스테네스의 체로 소수 구해놓기
    for(int i=2; i*i<=MAX; ++i)
        if(v[i] == false)
            for(int j=i+i; j<=MAX; j+=i)
                v[j] = true;
    
    /// 2) 소수인지, numbers의 문자열로 구성된 숫자인지 확인하기
    for(int i=2; i<=MAX; i++) {
        if(v[i]==false) {
            if(compare(i,numbers)) {
                printf("%d\n",i);
                Ans++;
            }
        }
    }
    return Ans;
}
#endif
