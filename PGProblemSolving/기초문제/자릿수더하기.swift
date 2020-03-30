//
//  자릿수더하기.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 14/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 자릿수더하기 : Adding Digits

// MARK: 숫자 각 자리의 숫자를 합한 결과를 출력하라!!

import Foundation

func addingDigits(_ n: Int) -> Int {
    var num = n
    var Ans = 0
    while num > 0 {
        Ans += num % 10
        num /= 10
    }
    return Ans
}
