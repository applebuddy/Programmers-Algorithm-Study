//
//  예상대진표_Lv2.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/20.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: 예상 대진표 Lv2

/*
import Foundation

func getNextNum(_ num: inout Int) {
    if num == 1 { return }
    else {
        if num%2 == 0 { num /= 2 }
        else { num = (num+1) / 2 }
    }
}

func solution(_ n:Int, _ a:Int, _ b:Int) -> Int
{
    var A = a, B = b, Ans = 0
    if a > b { swap(&A, &B) }
    while(true) {
        getNextNum(&A)
        getNextNum(&B)
        Ans += 1
        if B - A == 0 { break }
    }
    return Ans
}
*/
