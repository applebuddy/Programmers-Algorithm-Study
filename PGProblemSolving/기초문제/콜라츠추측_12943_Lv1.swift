//
//  콜라츠추측_12943_Lv1.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/24.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 콜라츠 추측 12943 Lv1

import Foundation

func colatzGuess(_ num: Int) -> Int {
    var Cnt = 0, N = num
    if N == 1 { return 0 }
    while true {
        Cnt += 1
        if Cnt > 500 { return -1 }
        if N % 2 == 0 { N /= 2 }
        else { N *= 3; N += 1 }
        if N == 1 { break }
    }
    return Cnt
}
