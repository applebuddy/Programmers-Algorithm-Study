//
//  문자열_내마음대로_정렳가ㅣ.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 12/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 문자열 내 마음대로 정렬하기

// n번째 문자를 기준으로 문자들을 정렬해보자! 만약 문자가 같다면 사전순으로 정렬하라!

import Foundation

func customArrange(_ strings: [String], _ n: Int) -> [String] {
    return strings.sorted {
        if Array($0)[n] > Array($1)[n] {
            return false
        } else if Array($0)[n] == Array($1)[n] {
            return $0 < $1
        } else {
            return true
        }
    }
}
