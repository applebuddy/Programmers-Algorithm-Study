//
//  최소공배수와최대공약수_Lv1.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 최소공배수와 최대공약수

// MARK: N,M의 최소공배수와 최대공약수를 구해라!!

import Foundation

func getGCD(a: Int, b: Int) -> Int {
    if b == 0 { return a }
    return getGCD(a: b, b: a % b)
}

func getLCD(a: Int, b: Int) -> Int {
    return a * b / getGCD(a: a, b: b)
}

func getGCDnLCD(_ n: Int, _ m: Int) -> [Int] {
    return [getGCD(a: n, b: m), getLCD(a: n, b: m)]
}
