//
//  문자열 다루기 기본.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 03/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

import Foundation

func solution1(_ s: String) -> Bool {
    return (Int(s) != nil) && (s.count == 4 || s.count == 6) ? true : false
}
