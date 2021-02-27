//
//  약수의합.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 14/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 약수의 합 : Sum of the Factor

// MARK: 주어진 수, n의 모든 약수의 합을 출력하라!!

import Foundation

func sumOfTheFactorWithHighOrderFunction(_ n: Int) -> Int {
    return n == 0 ? 0 : (1...n).map { n % $0 == 0 ? $0 : 0 }.reduce(0, +)
}

func sumOfTheFactor(_ n: Int) -> Int {
    if n == 0 || n == 1 { return n }
    var Ans = 0
    for i in 1 ... n / 2 {
        if n % i == 0 {
            Ans += i
        }
    }
    return Ans + n
}
