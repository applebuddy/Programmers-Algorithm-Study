//
//  타겟넘버_43165.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 08/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 타겟 넘버
// 주어진 배열(numbers)의 숫자 사이에 +/- 를 넣어 타겟넘버(target)를 만들 수 있는 경우의 수를 출력하라.


/// 통과 답안, DP활용, 조수환님 코드
#if 0
#include <string>
#include <vector>

using namespace std;

int canGetNumber(const vector<int> & numbers, const int & target, int k, int current, vector<vector<int>> & cache) {
    if(k == numbers.size()) {
        if(target == current)
            return cache[k][current+1000] = 1;
        else
            return cache[k][current+1000] = 0;
    } else {
        if(cache[k][current+1000] != -1001)
            return cache[k][current+1000];
        
        return cache[k][current+1000] = canGetNumber(numbers, target, k+1, current+numbers[k], cache)
        + canGetNumber(numbers, target, k+1, current-numbers[k], cache);
    }
}

int targetNumber(vector<int> numbers, int target) {
    vector<vector<int>> cache(21, vector<int>(2001, -1001));
    int answer = canGetNumber(numbers, target, 0, 0, cache);
    return answer;
}
#endif

// 단순 재귀 활용 복습풀이 답안, '19. 12. 15.
#if 0
#include <string>
#include <vector>

using namespace std;

int Ans = 0;
vector<int> DP(1001,0);

void targetNumber(int idx, int sum, vector<int> &numbers, int &target) {
    if(idx == numbers.size() && sum==target) Ans++;
    if(idx >= numbers.size()) return;
    
    targetNumber(idx+1, sum-numbers[idx], numbers, target);
    targetNumber(idx+1, sum+numbers[idx], numbers, target);
    return;
}

int solution(vector<int> numbers, int target) {
    targetNumber(0, 0, numbers, target);
    return Ans;
}
#endif

/// 통과 답안, '19. 10. 11.

//#include <string>
//#include <vector>
//
//using namespace std;
//
//int Ans = 0;
//
//void DFS(vector<int> numbers, int target, int count, int sum) {
//    if(numbers.size() < count) return;
//    if(target==sum && count==numbers.size()) Ans++;
//    DFS(numbers,target,count+1,sum+numbers[count]);
//    DFS(numbers,target,count+1,sum-numbers[count]);
//    return;
//}
//
//int solution(vector<int> numbers, int target) {
//    DFS(numbers, target, 0, 0);
//    return Ans;
//}


/// 통과 답안, '19. 05.
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> num;
//int answer = 0;
//void getCount(int k, int count, int sum) {
//    // count가 초과하면 함수를 종료한다.
//    if(count>num.size()) return;
//    // count가 num의 길이와 일치하고, 현재까지의 합이 타겟넘버(k)가 되었다면 ++ 카운팅 후 함수를 종료한다.
//    else if(count==num.size() && sum==k) {
//        answer++;
//        return;
//    }
//
//    // 재귀함수 호출을 통해 더하는경우(+), 빼는경우(-)를 확인한다.
//    getCount(k, count+1, sum-num[count]);
//    getCount(k, count+1, sum+num[count]);
//}
//
//int targetNumber(vector<int> numbers, int target) {
//    num = numbers;
//    // (1번째 인자)target넘버가 num배열의 길이만큼 되었을때 몇번 만들어 질 수 있는지 확인한다.
//    // (2번째 인자)재귀함수 실행 간 현재까지의 계산된 길이
//    // (3번째 인자)재귀함수 실행 간 총 연산된 결과값으로 타겟넘버와 비교할 값
//    getCount(target, 0, 0);
//
//    return answer;
//}
