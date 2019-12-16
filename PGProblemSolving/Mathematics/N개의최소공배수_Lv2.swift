//
//  N개의최소공배수.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - N개의 최소공배수

// MARK: [Int] 배열, arr이 주어진다. arr의 숫자 전체에 대한 최소공배수(LCD)를 반환하라!!!

import Foundation

func calcGCD(a: Int, b: Int) -> Int {
    if b == 0 { return a }
    return getGCD(a: b, b: a % b)
}

func calcLCD(a: Int, b: Int) -> Int {
    return a * b / calcGCD(a: a, b: b)
}

func getLCDs(_ arr: [Int]) -> Int {
    var Ans = arr[0]
    for i in 1 ..< arr.count {
        Ans = calcLCD(a: Ans, b: arr[i])
    }
    return Ans
}
