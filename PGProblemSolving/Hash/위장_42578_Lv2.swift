//
//  위장_42578_Lv2.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2020/03/11.
//  Copyright © 2020 MinKyeongTae. All rights reserved.
//

// MARK: - 위장 42578 Lv2
// MARK: Hash 문제풀이

/*
import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var dic = [String:Int]()
    var Ans = 1
    for i in clothes.indices {
        let type = clothes[i][1]
        dic[type] = (dic[type] ?? 0) + 1
    }
    
    if dic.count == 1 { return clothes.count }
    
    for (key, value) in dic {
        Ans *= (value + 1)
    }
    
    return Ans - 1
}
*/
