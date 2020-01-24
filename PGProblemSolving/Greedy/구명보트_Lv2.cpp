//
//  구명보트.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 10/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: 구명보트 Lv2

// MARK: - 구명보트 while문 풀이답안
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int i=0, j = people.size()-1;
    while(i<=j) {
        if(people[i] + people[j] <= limit) {
            i++;
            j--;
            answer++;
            continue;
        } else {
            j--;
            answer++;
        }
    }
    return answer;
}
#endif

#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;

int lifeBoat_3(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int i=0;
    for(int j=(int)people.size()-1; j>=i; j--) {
        if(people[i]+people[j]<=limit) {
            answer++;
            i++;
        }
        else answer++;
    }
    return answer;
}
#endif

// MARK: - Reviewing Problem '19. 09. 23.
//int lifeBoat(vector<int> people, int limit) {
//    int answer = 0;
//    sort(people.begin(), people.end()); //오름차순으로 사람의 체중을 정렬한다.(최대몸무게는 limit보다 작음)
//    int i=0,j=0;
//    for(j=int(people.size()-1); j>=i; j--){ // 가장 체중이 큰 사람부터 탐색한다.
//        if(people[i]+people[j]<=limit){ //가장 가벼운 체중, 현재 탐색중인 체중이 limit보다 작나 본다.
//            i++; // 두명을 동시 수용 가능하면 가벼운체중탐색인덱스, i를 증가시킨다.
//            answer++; // 보트하나 사용
//        }else{ // 두명을 동시 수용 불가능하면 가장 무거운체중한명만 보트에 태운다.
//            answer++; // 보트하나 사용
//        }
//    }
//
//    return answer;
//}

// MARK: - Reviewing Problem '19. 09. 17.
//int lifeBoat(vector<int> people, int limit) {
//    int answer = 0;
//    sort(people.begin(), people.end());
//    int j = 0;
//    for(int i=people.size()-1; i>=j; i--) {
//        if(people[j] + people[i] <= limit) {
//            j++;
//            answer++;
//        } else {
//            answer++;
//        }
//
//    }
//    return answer;
//}
