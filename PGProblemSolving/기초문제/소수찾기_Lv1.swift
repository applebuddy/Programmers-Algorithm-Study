//
//  소수찾기.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 12/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 소수찾기 : Find The Prime 1단계 문제

// 1 ~ N 범위 내 소수의 갯수를 출력하라!

import Foundation

func findPrime(_ n: Int) -> Int {
    var chk = [Bool](repeating: true, count: n + 1)
    var Ans = 0
    for i in stride(from: 2, through: Int(sqrt(Double(n))), by: 1) {
        if chk[i] == true {
            for j in stride(from: i + i, through: n, by: i) {
                chk[j] = false
            }
        }
    }

    for i in 2 ... n {
        if chk[i] == true { Ans += 1 }
    }
    return Ans
}

// func findPrime2(_ n:Int) -> Int {
//    var chk = [Bool](repeating: true, count: n+1)
//    var Ans = 0
//    for i in stride(from: 2, through: Int(Double(n).squareRoot()), by: 1) {
//        if chk[i] == true {
//            for j in stride(from: i+i, through: n, by: i) {
//                chk[j] = false
//            }
//        }
//    }
//
//    for i in 2...n {
//        if chk[i] == true { Ans += 1 }
//    }
//    return Ans
// }
