//
//  정수내림차순으로배치하기_12933_Lv1.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/21.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

import Foundation

func solution(_ n: Int64) -> Int {
    var array: [Int] = []

    for number in String(n) {
        array.insert(Int(String(number)) ?? 0, at: 0)
    }

    var str = ""
    array.sort(by: >)
    array.forEach {
        str += String($0)
    }

    return Int(str)!
}
