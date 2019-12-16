//
//  시저암호.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 14/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 시저암호

// K번만큼 알파벳을 우측 이동 시킨 알바벳값을 출력해라
// * 대소문자 구분, Z, z 넘어갈시 A, a로 변환

import Foundation

func sizierCode(_ s: String, _ n: Int) -> String {
    var arr = Array(s)

    for i in arr.indices {
        for _ in 0 ..< n {
            if arr[i] == " " { break }
            let ascV = Int(arr[i].unicodeScalars.first!.value)
            if ascV == 122 { arr[i] = "a"; continue }
            if ascV == 90 { arr[i] = "A"; continue }
            arr[i] = Character(Unicode.Scalar(ascV + 1)!)
        }
    }
    return arr.map { String($0) }.joined()
}
