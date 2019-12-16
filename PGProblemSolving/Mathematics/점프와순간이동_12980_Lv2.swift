//
//  점프와순간이동_12980_Lv2.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 08/10/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

import Foundation

func jumpAndTeleport(_ n: Int) -> Int {
    var Ans = 0
    var N = n
    while N != 0 {
        if N % 2 == 0 {
            N /= 2
        } else {
            N -= 1
            Ans += 1
        }
    }
    return Ans
}
