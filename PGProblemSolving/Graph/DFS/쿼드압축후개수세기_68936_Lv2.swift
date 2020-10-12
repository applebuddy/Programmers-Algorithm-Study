
// MARK: - 쿼드압축 후 개수세기 68936

// MARK: DFS swift 문제풀이

var G = [[Int]]()
var Ans = (0, 0)

func DFS(_ x: Int, _ y: Int, _ len: Int) {
    var isEqual = true
    var target = G[x][y]
    for idx in x ..< x+len {
        for jdx in y ..< y+len {
            if target != G[idx][jdx] {
                isEqual = false
                break
            }
        }
        if !isEqual { break }
    }
    
    if !isEqual {
        DFS(x, y, len/2)
        DFS(x, y+len/2, len/2)
        DFS(x+len/2, y, len/2)
        DFS(x+len/2, y+len/2, len/2)
    } else {
        if target == 0 { Ans.0 += 1 }
        else { Ans.1 += 1 }
    }
}

func solution(_ arr:[[Int]]) -> [Int] {
    G = arr
    DFS(0, 0, arr.count)
    return [Ans.0, Ans.1]
}
