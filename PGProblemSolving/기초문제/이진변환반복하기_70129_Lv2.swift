
// MARK: - 이진 변환 반복하기
// MARK: Lv2 swift 문제풀이

import Foundation

func solution(_ s:String) -> [Int] {
    var S = s
    var Ans: (cnt: Int, rTot: Int) = (0, 0)
    while S != "1" {
        let sLen = S.count
        let remLen = S.reduce(into: 0) { $0 += $1 != "0" ? 1 : 0 }
        Ans.rTot += sLen - remLen
        Ans.cnt += 1
        S = String(remLen, radix: 2)
    }
    
    return [Ans.0, Ans.1]
}
