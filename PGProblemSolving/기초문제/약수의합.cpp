//
//  약수의합.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 14/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

int sumOfTheFactor(int n) {
    if(n==1 || n==0) return n;
    int answer = 0;
    for(int i=1; i<=n/2; i++){
        if(n%i == 0) answer+=i;
    }
    return answer + n;
}
