//
//  종이접기_62049_Lv3.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2020/03/13.
//  Copyright © 2020 MinKyeongTae. All rights reserved.
//

// MARK: - 종이접기 Lv3
// MARK: swift 문제풀이
/*
import Foundation

func solution(_ n:Int) -> [Int] {
    var pv = [0]
    if n == 1 { return pv }
    for i in 2...n {
        pv = pv + [0] + pv.map { $0 == 0 ? 1 : 0 }.reversed()
    }
    return pv
}
*/
