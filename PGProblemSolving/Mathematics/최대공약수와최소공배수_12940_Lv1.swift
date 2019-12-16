//
//  최대공약수와최소공배수_12940_Lv1.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/23.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 최대공약수와 최소공배수_12940_Lv1

import Foundation

func getGCD(_ A: Int, _ B: Int) -> Int {
    if B == 0 { return A }
    else { return getGCD(B, A % B) }
}

func getLCD(_ A: Int, _ B: Int) -> Int {
    return A * B / getGCD(A, B)
}

func solution(_ n: Int, _ m: Int) -> [Int] {
    return [getGCD(n, m), getLCD(n, m)]
}
