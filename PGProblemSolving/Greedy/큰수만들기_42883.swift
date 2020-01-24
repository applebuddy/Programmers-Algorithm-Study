//
//  큰수만들기_42883.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2020/01/25.
//  Copyright © 2020 MinKyeongTae. All rights reserved.
//

// MARK: 큰수만들기 Lv2
/*
import Foundation

func solution(_ number:String, _ k:Int) -> String {
    var arr = Array(number).compactMap { String($0) }
    var K = k
    var Ans = [String]()
    for i in arr.indices {
        while K > 0 && !Ans.isEmpty && Ans.last! < arr[i] {
            Ans.removeLast()
            K -= 1
        }

        if K <= 0 {
            Ans.append(contentsOf: arr[i...])
            break
        } else {
            Ans.append(arr[i])
        }
    }
    return Ans[0..<number.count-k].joined()
}
*/
