
import Foundation

var chk = [[Bool]](repeating: [Bool](repeating: false, count: 101), count: 101)
var G = [[Int]](repeating: [Int](), count: 101)

func BFS(_ num: Int) {
    var Q: [Int] = [num]
    var cur = 0
    while cur < Q.count {
        let node = Q[cur]
        cur += 1
        G[node].forEach { next in
            if chk[num][next] == true { return }
            chk[num][next] = true
            chk[next][num] = true
            Q.append(next)
        }
    }
}

func solution(_ n: Int, _ results: [[Int]]) -> Int {
    (1 ... n).forEach { num in
        chk[num][num] = true
    }

    results.forEach { result in
        G[result[0]].append(result[1])
    }

    (1 ... n).forEach { num in
        BFS(num)
    }

    return (1 ... n).reduce(into: 0) { result, num in
        var good = true
        for target in 1 ... n {
            if chk[num][target] == false { good = false; break }
        }

        result += good ? 1 : 0
    }
}
