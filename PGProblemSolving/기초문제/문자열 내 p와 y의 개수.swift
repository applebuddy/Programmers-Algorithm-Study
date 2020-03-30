//
//  문자열 내 p와 y의 개수.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 03/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

import Foundation

func solution2(_ s: String) -> Bool {
    let chkString = s.lowercased()
    var chkArr = (0, 0)

    for c in chkString {
        if c == "p" { chkArr.0 += 1 }
        if c == "y" { chkArr.1 += 1 }
    }

    return chkArr.0 == chkArr.1 ? true : false
}
