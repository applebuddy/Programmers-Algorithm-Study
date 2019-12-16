//
//  큰 수 만들기.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 10/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 큰 수 만들기 : Greredy Problem, 탐욕법 문제
// MARK: k개의 수를 제거했을 때 얻을 수 있는 제일 큰 수를 구해라!!

#include <string>
#include <vector>

using namespace std;

string getBiggestNumber(string number, int k) {
    string answer = number.substr(k);
    
    for(int i=k-1; i>=0; i--) {
        int j = 0;
        do {
            if(answer[j] <= number[i]) {
                swap(answer[j], number[i]);
                j++;
            }
            else break;
        }while(1);
    }
    
    return answer;
}

//string solution(string number, int k) {
//    string answer = "";
//    answer = number.substr(k);
//    printf("%s\n",answer.c_str());
//    for(int i=k-1; i>=0; i--){
//        int j=0;
//        do{
//            if(answer[j]<=number[i]){
//                char temp = answer[j];
//                answer[j] = number[i];
//                number[i] = temp;
//                printf("%s\n",answer.c_str());
//                j++;
//            }else{
//                break;
//            }
//        }while(1);
//    }
//    return answer;
//}
