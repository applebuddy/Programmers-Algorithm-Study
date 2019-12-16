//
//  전화번호 목록.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 10/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool phoneCallList(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size()-1; i++){
        if(phone_book[i]==phone_book[i+1].substr(0,phone_book[i].size())) {
            answer = false;
            break;
        }
    }
    return answer;
}
