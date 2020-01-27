//
//  예산_43237_Lv3.cpp
//  BackJoonPractice
//
//  Created by MinKyeongTae on 10/10/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: 예산 Lv3

// MARK: - 예산 복습 문제풀이
#if 0
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    sort(budgets.begin(), budgets.end());
    int answer = 0, left = 0, right = budgets.back();
    while(left <= right) {
        int mid = (left + right) / 2, tot = 0;
        for(int i=0; i<budgets.size(); i++) {
            if(budgets[i]<=mid) tot += budgets[i];
            else tot += mid;
        }
        
        if(tot <= M) {
            answer = mid;
            left = mid + 1;
        } else right = mid - 1;
    }
    return answer;
}
#endif


/// MARK: - 훨씬 간결한 타 답안 예시)
#if 0
/// MARK: - 예산문제 복습답안
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int theBudgets(vector<int> budgets, int M) {
    int answer = 0;
    int len = (int)budgets.size();
    
    // 오름차순 정렬 후 차례대로 비교를 하여 최적 상한선을 구한다 .
    sort(budgets.begin(), budgets.end());
    auto iter = budgets.begin();
    for(; iter!=budgets.end(); iter++) {
        if(*iter > M/len) return M/len;
        else M-=*iter;
        len--;
    }
    return answer = budgets.back();
}

//int solution(vector<int> budgets, int M) {
//    int numbers = (int)budgets.size();
//
//    sort(budgets.begin(),budgets.end());
//
//    for(auto itr=budgets.begin(); itr!= budgets.end(); itr++){
//        if(*itr > (M / numbers)) return M/numbers;
//        else{
//            M -= *itr;
//            numbers--;
//        }
//    }
//
//    return budgets.back();
//}

#endif


/// MARK: - 내 풀이 답안 : Binary Searching Algorithm Problem
#if 0
#include <string>
#include <vector>

using namespace std;

/// MARK: 추가 함수 미사용 풀이 답안 : Binary Searching Algorithm Problem
int theBudgets(vector<int> budgets, int M) {
    int answer = 0;
    sort(budgets.begin(), budgets.end());
    int left = budgets.front();
    int right = budgets.back();
    int len = budgets.size();
    if(left > M/len) return M/len;
    while(left <= right) {
        int mid = (left+right)/2;
        int sum = 0;
        for(int i=0; i<budgets.size(); i++) {
            if(mid > budgets[i]) sum+=budgets[i];
            else sum+=mid;
        }
        if(sum > M) {
            right = mid-1;
        } else {
            answer = mid;
            left = mid+1;
        }
    }
    return answer;
}

/// MARK: 첫 풀이 답안 : Binary Searching Algorithm Problem
//bool isOver(const vector<int> &V, const int &d, const int &M) {
//    long long sum=0;
//    for(auto v: V) {
//        if(v>d) sum+=d;
//        else sum+=v;
//    }
//
//    return sum <= M ? false : true;
//}
//
//int theBudget(vector<int> budgets, int M) {
//    long long sum=0, max=0, min=2e9, Ans=0, left, right, mid, total;
//    int len = (int)budgets.size();
//    for(auto v : budgets) {
//        sum+=v;
//        max = v>max ? v : max;
//        min = v<min ? v : min;
//    }
//
//    if(sum<=M) return max;
//    if(min>M/len) return M/len;
//
//    Ans = min;
//    left = min, right = M;
//
//    while(left <= right) {
//        mid = (left+right)/2;
//        if(Ans < mid && !isOver(budgets,mid,M)) {
//            Ans = mid;
//            left = mid+1;
//        }
//        else {
//            right = mid-1;
//        }
//    }
//    return Ans;
//}
#endif
