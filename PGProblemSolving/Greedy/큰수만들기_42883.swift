//
//  큰수만들기_42883.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2020/01/25.
//  Copyright © 2020 MinKyeongTae. All rights reserved.
//

// MARK: 큰수만들기 Lv2
/*
func solution(_ number:String, _ k:Int) -> String {
    let nCount = number.count
    let arr = Array(number)
    var answer: [Character] = []
    var K = k
    for index in arr.indices {
        while K > 0 && !answer.isEmpty && answer.last! < arr[index] {
            answer.removeLast()
            K -= 1
        }
        
        if K == 0 {
            answer.append(contentsOf: Array(arr[index...]))
            break
        } else {
            answer.append(arr[index])
        }
    }
    
    return String(answer[0..<nCount - k])
}
*/
