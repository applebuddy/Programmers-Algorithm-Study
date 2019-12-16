//
//  124나라의숫자.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 124 나라의 숫자
/// MARK: 124 나라가 있습니다. 124 나라에서는 10진법이 아닌 다음과 같은 자신들만의 규칙으로 수를 표현합니다.
/// * 124 World's Rules
//    - 124 나라에는 자연수만 존재합니다.
//    - 124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용합니다.

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n>0) {
        int temp = n%3;
        char ch = "412"[temp];
        if(ch == '4') n--;
        answer = ch + answer;
        n /= 3;
    }
    return answer;
}
