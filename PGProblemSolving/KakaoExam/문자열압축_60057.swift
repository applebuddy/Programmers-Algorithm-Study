
// MARK: - 문자열 압축 60057

// MARK: swift 문제풀이

import Foundation

func dupLen(of dupCnt: Int) -> Int {
    if dupCnt >= 100 {
        return 3
    } else if dupCnt >= 10 {
        return 2
    }

    return 1
}

func stringCompression(_ s: String) -> Int {
    let arr = Array(s)
    var mxLen = arr.count
    var Ans = mxLen

    if mxLen <= 2 { return Ans }
    for len in 1 ... mxLen / 2 {
        var STK = [String]()
        var cnt = 0
        var dup = 1
        var addLen = 0
        var str = ""
        for char in arr {
            str += "\(char)"
            cnt += 1
            if cnt == len {
                if !STK.isEmpty, STK.last! == str {
                    dup += 1
                } else {
                    if dup > 1 {
                        addLen += dupLen(of: dup)
                        dup = 1
                    }
                    STK.append(str)
                }
                cnt = 0
                str = ""
            }
        }
        let nowLen = STK.count * len + cnt + addLen + (dup > 1 ? dupLen(of: dup) : 0)
        Ans = Ans > nowLen ? nowLen : Ans
    }

    return Ans
}
