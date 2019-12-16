//
//  서울에서김서방찾기.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 13/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 서울에서 김서방 찾기

import Foundation

func findKim(_ seoul: [String]) -> String {
    // * 해당 문제와 같은 경우, [String].index(of:)/firstIndex(of:)/lastIndex(of:) 전부 사용 가능
    // 1) index(of:) -> is Deprecated, Use firstIndex instead.
//    return "김서방은 \(seoul.index(of: "Kim")!)에 있다"

    // 2)
    return "김서방은 \(seoul.firstIndex(of: "Kim")!)에 있다"

    // 3)
    // return "김서방은 \(seoul.firstIndex(of: "Kim")!)에 있다"
}
