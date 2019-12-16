//
//  가운데글자가져오기.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 02/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 가운데 글자 가져오기

import Foundation

func solution(_ s: String) -> String {
    return s.count % 2 == 0 ? "\(Array(s)[s.count / 2 - 1])\(Array(s)[s.count / 2])" : "\(Array(s)[s.count / 2])"
}
