//
//  가장큰수_42746_Lv2.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/23.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 가장 큰 수_42746_Lv2

import Foundation

func solution(_ numbers: [Int]) -> String {
    var Ans: String = ""
    numbers.sorted { "\($0)\($1)" > "\($1)\($0)" }.forEach { Ans += "\($0)" }
    return Array(Ans)[0] == "0" ? "0" : Ans
}
