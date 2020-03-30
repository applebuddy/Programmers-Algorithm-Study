//
//  체육복.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 13/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: 체육복 : Greedy Problem
// MARK: - n명의 학생, 체육복은 기본적으로 한벌씩 있으나, lost, reserve 인덱스의 학생들은 여벌이 있거나 잃어버진 학생이 있다.
// * 체육복은 양 옆 번호의 학생들에게만 빌려줄 수 있다. (1번 학생은 2번에게만, 2번학생은 1/3번 학생으로부터 체육복을 빌릴 수 있다.)
// -> 최대한 많은 사람이 체육복을 입을 수 있도록 한 뒤 그 학생의 수를 출력해라!

// MARK: - 체육복 Lv2 복습 문제풀이
#if 0
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> V(n+1, 1);
    for(auto &v: reserve) V[v]++;
    for(auto &v: lost) V[v]--;
    for(int i=1; i<V.size(); i++) {
        if(V[i]>0) continue;
        if(i!=1 && V[i-1]>1) {
            V[i-1]--;
            V[i]++;
            continue;
        }

        if(i!=V.size()-1 && V[i+1]>1) {
            V[i+1]--;
            V[i]++;
        }
    }
    
    for(int i=1; i<V.size(); i++) if(V[i]>=1) answer++;
    return answer;
}
#endif

#if 0
#include <string>
#include <vector>

using namespace std;

int gymSuit(int n, vector<int> lost, vector<int> reserve) {
    vector<int> stu(n,1);
    int Ans = 0;
    for(auto l : lost) stu[l-1]--;
    for(auto r : reserve) stu[r-1]++;
    
    for(int i=0; i<n; i++) {
        if(stu[i] < 1) {
            if(stu[i-1]>1 && i != 0) {
                stu[i-1]--;
                stu[i]++;
                
            } else if(stu[i+1]>1 && i != n-1) {
                stu[i+1]--;
                stu[i]++;
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        if(stu[i]>=1) Ans++;
    }
    
    return Ans;
}
#endif
