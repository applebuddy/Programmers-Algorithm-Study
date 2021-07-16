
let numberInfoList: [(String, Int)] = [("zero", 4), ("one", 3), ("two", 3), ("three", 5),
                                       ("four", 4), ("five", 4), ("six", 3), ("seven", 5),
                                       ("eight", 5), ("nine", 4)]

extension Array where Element == Character {
    func getNumber(at oIndex: Int) -> (number: Int, length: Int) {
        for (index, numberInfo) in numberInfoList.enumerated()
            where oIndex + numberInfo.1 - 1 < count {
            var good = true
            var nowIndex = oIndex
            for numberChar in numberInfo.0 {
                if self[nowIndex] != numberChar {
                    good = false; break
                }
                nowIndex += 1
            }
            if good { return (index, numberInfo.1) }
        }
        return (0, 4)
    }
}

func solution(_ s: String) -> Int {
    let array = Array(s)
    var answer: Int = 0
    var index: Int = 0
    while index < array.count {
        let char = array[index]
        if char.isNumber {
            answer = answer * 10 + Int(char.asciiValue!) - 48
            index += 1
        } else {
            let numberInfo = array.getNumber(at: index)
            answer = answer * 10 + numberInfo.number
            index += numberInfo.length
        }
    }
    return answer
}
