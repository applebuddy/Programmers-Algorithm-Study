
func makeArray(_ rows: Int, _ columns: Int) -> [[Int]] {
    return (0 ..< rows).reduce(into: [[Int]]()) { result, rowIndex in
        let startNum = rowIndex * columns + 1
        result.append([Int](startNum ..< startNum + columns))
    }
}

typealias Pos = (x: Int, y: Int)
let dx = [0, 1, 0, -1]
let dy = [1, 0, -1, 0]

extension Array where Element == [Int] {
    mutating func rotate(_ startPos: Pos, _ endPos: Pos) -> Int {
        var tempArray = self
        var minValue = self[startPos.x][startPos.y]
        var index = startPos
        dx.indices.forEach { dirIndex in
            while true {
                let targetX = index.x + dx[dirIndex]
                let targetY = index.y + dy[dirIndex]
                if targetX < startPos.x || targetX > endPos.x
                    || targetY < startPos.y || targetY > endPos.y { break }
                tempArray[targetX][targetY] = self[index.x][index.y]
                index = (targetX, targetY)
                minValue = minValue > self[targetX][targetY] ? self[targetX][targetY] : minValue
            }
        }
        self = tempArray
        return minValue
    }
}

func solution(_ rows: Int, _ columns: Int, _ queries: [[Int]]) -> [Int] {
    var array: [[Int]] = makeArray(rows, columns)
    return queries.reduce(into: [Int]()) { answer, query in
        answer.append(array.rotate((query[0] - 1, query[1] - 1),
                                   (query[2] - 1, query[3] - 1)))
    }
}
