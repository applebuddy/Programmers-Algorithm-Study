
import Foundation

var answer: Int = 0
var Numbers = [Int]()
var Target: Int = 0
func DFS(_ idx: Int, _ result: Int) {
    if idx >= Numbers.count {
        if result == Target { answer += 1 }
        return
    }
    DFS(idx + 1, result - Numbers[idx])
    DFS(idx + 1, result + Numbers[idx])
}

func solution(_ numbers: [Int], _ target: Int) -> Int {
    Numbers = numbers
    Target = target
    DFS(0, 0)
    return answer
}
