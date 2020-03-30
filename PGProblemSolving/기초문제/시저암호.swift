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

/*
func solution(_ s:String, _ n:Int) -> String {
    return Array(s).map {
        let ascii = Int($0.asciiValue!)
        var nAscii = 48
        nAscii = ascii + n
        if ascii >= 65 && ascii <= 90 {
            nAscii = nAscii > 90 ? 65+(nAscii-91) : nAscii
        } else if ascii >= 97 && ascii <= 122 {
            nAscii = nAscii > 122 ? 97+(nAscii-123) : nAscii
        } else { return " " }
        return String(Unicode.Scalar(nAscii)!)
    }.joined()
}
*/
