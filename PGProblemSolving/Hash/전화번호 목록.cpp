//
//  전화번호 목록.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 10/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: 전화번호목록 문제풀이
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size()-1; i++) {
        if(phone_book[i] == phone_book[i+1].substr(0,phone_book[i].length())) return false;
    }
    
    return true;
}
#endif
