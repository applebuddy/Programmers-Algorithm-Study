
// MARK: - 3진법 뒤집기 68935

// MARK: swift 문제풀이

import Foundation

func solution(_ n:Int) -> Int {
    var N = n
    var list = [Int]()
    while N > 0 {
        list.append(N % 3)
        N /= 3
    }
    
    var tdx = 1
    var Ans = 0
    (list.reversed()).forEach {
        Ans += tdx * $0
        tdx *= 3
    }
    
    return Ans
}
