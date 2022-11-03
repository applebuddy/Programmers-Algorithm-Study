
import Foundation

typealias Pos = (x: Int, y: Int)
var answer = Int.max
var transferDic = [String: Bool]() // 중복환승 방지용
func DFS(_ pos: Pos, _ start: Int, _ end: Int, _ cnt: Int, _ subwayLlist: inout [[Int]], _ isStart: Bool) {
    let x = pos.x
    var y = pos.y
    if cnt >= answer { return }

    var isStationToStart = false
    for index in subwayLlist[x].indices where subwayLlist[x][index] == start {
        if isStart == false { break }
        y = index
        isStationToStart = true
        break
    }

    // 시작하는 호선에 start역이 없으면 그대로 재귀 종료
    if isStart && !isStationToStart { return }

    let nowStation = subwayLlist[x][y]
    if subwayLlist[x].count - 1 == y {
        var hasNoMoreStation = true
        for index in subwayLlist.indices {
            if index == x { continue }
            let subwayList = subwayLlist[index]
            for jndex in subwayList.indices where subwayList[jndex] == nowStation {
                if transferDic["\(pos.x) \(pos.y) -> \(index) \(jndex)"] != nil {
                    continue
                }
                hasNoMoreStation = false
                break
            }
        }

        if hasNoMoreStation { return }
    }

    for index in subwayLlist[x].indices where subwayLlist[x][index] == end {
        answer = answer > cnt ? cnt : answer
        return
    }

    for hndex in subwayLlist[x].indices {
        let station = subwayLlist[x][hndex]
        y = hndex
    for index in subwayLlist.indices {
        if index == x { continue }
        let subwayList = subwayLlist[index]

        // 환승할 곳이 있는지 확인
        for jndex in subwayList.indices where subwayList[jndex] == station {
            let toPos: Pos = (index, jndex)
            if transferDic["\(pos.x) \(y) -> \(toPos.x) \(toPos.y)"] != nil {
                continue
            }
            transferDic["\(toPos.x) \(toPos.y) -> \(pos.x) \(y)"] = true
            transferDic["\(pos.x) \(y) -> \(toPos.x) \(toPos.y)"] = true
            DFS(toPos, index, end, cnt+1, &subwayLlist, false)
            transferDic["\(toPos.x) \(toPos.y) -> \(pos.x) \(y)"] = nil
            transferDic["\(pos.x) \(y) -> \(toPos.x) \(toPos.y)"] = nil
        }
    }
    }
}

func solution(_ subway:[String], _ start:Int, _ end:Int) -> Int {
    var subwayLlist = subway
        .map { Array($0).split(separator: " ").map { Int(String($0))! } }
    for startX in subway.indices {
        DFS((startX, 0), start, end, 0, &subwayLlist, true)
        transferDic = [String: Bool]() // 중복환승 방지용
    }

    return answer
}
