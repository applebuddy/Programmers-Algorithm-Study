//
//  짝지어제거하기_Lv2.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 짝지어 제거하기 : Word Compression

// MARK: 연속으로 같은 문자열을 하나씩 제거해서 모두 제거할 수 있는지 여부를 확인해라!!!

/*
 import Foundation

 func removePairValue(_ s: String) -> Int {
 var STK = [Character]()
 var arr = Array(s)

 for i in arr.indices {
     if STK.isEmpty { STK.append(arr[i]) }
     else {
         if STK.last! == arr[i] { STK.removeLast() }
         else { STK.append(arr[i]) }
     }
 }
 return STK.isEmpty ? 1 : 0
 }
 */
