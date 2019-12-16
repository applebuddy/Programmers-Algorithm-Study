//
//  두 정수 사이의 합.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 02/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

import Foundation

// MARK: 단순 for문을 사용 한 풀이 (가장 시간소비가 적음)

func solution(_ a: Int, _ b: Int) -> Int64 {
    var ans = 0
    for i in a > b ? b ... a : a ... b {
        ans += i
    }

    return Int64(ans)
}

//// MARK: reduce를 사용 한 풀이
// func solution2(_ a:Int, _ b:Int) -> Int64 {
//    return Int64(Array(a>b ? b...a : a...b).reduce(0, +))
// }
//
//// MARK: enumerated()를 사용한 풀이
// func solution1(_ a:Int, _ b:Int) -> Int64 {
// var arr = Array(a>b ? b...a : a...b)
// var ans = 0
// for (_,value) in arr.enumerated() {
//     ans += value
// }
// return Int64(ans)
// }
