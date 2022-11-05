# Programmers-Algorithm-Study
Uploading programmers study source codes for the first time



# Level 0

### 옹알이 (1)

- link : https://school.programmers.co.kr/learn/courses/30/lessons/120956

~~~swift
import Foundation

func solution(_ babbling: [String]) -> Int {
    let dic: [String: Bool] = ["aya": true, "ye": true, "woo": true, "ma": true]
    return babbling.reduce(into: 0) { ans, str in
        var tDic = dic
        var temp = ""
        str.forEach { char in
            temp += "\(char)"
            if tDic[temp] == true {
                tDic[temp] = nil
                temp = ""
            }
        }
        ans += temp.isEmpty ? 1 : 0
    }
}
~~~



### 다음에 올 숫자

- link : https://school.programmers.co.kr/learn/courses/30/lessons/120924

~~~swift
import Foundation

func solution(_ common: [Int]) -> Int {
    if common[1] - common[0] == common[2] - common[1] {
        let diff = common[1] - common[0]
        return common.last! + diff
    } else {
        let diff = common[1] / common[0]
        return common.last! * diff
    }
}
~~~



### 진료 순서 정하기

- link : https://school.programmers.co.kr/learn/courses/30/lessons/120835

~~~swift
import Foundation

func solution(_ emergency: [Int]) -> [Int] {
    let sorted = emergency.enumerated().sorted { $0.element > $1.element }
    let dic = sorted.enumerated().reduce(into: [Int: Int]()) { dic, tuple in
        dic[tuple.1.1] = tuple.0 + 1
    }
    
    return emergency.reduce(into: [Int]()) { ans, elem in
        ans.append(dic[elem]!)
    }
}
~~~



### 공 던지기

- link : https://school.programmers.co.kr/learn/courses/30/lessons/120843

~~~swift
import Foundation

func solution(_ numbers: [Int], _ k:Int) -> Int {
    return numbers[(2 * k - 2) % numbers.count]
}
~~~



### 영어가 싫어요

- link : https://school.programmers.co.kr/learn/courses/30/lessons/120894

~~~swift
import Foundation

func solution(_ numbers: String) -> Int64 {
    let dic: [String: Int] = [
        "zero": 0, "one": 1, "two": 2, "three": 3, "four": 4, "five": 5,
        "six": 6, "seven": 7, "eight": 8, "nine": 9, "ten": 10
    ]
    var temp = ""
    return numbers.reduce(into: 0) { ans, char in
        temp += "\(char)"
        guard let num = dic[temp] else { return } 
        ans = ans * 10 + Int64(num)
        temp = ""
    }
}
~~~



### 최빈값 구하기

- link : https://school.programmers.co.kr/learn/courses/30/lessons/120812

~~~swift
import Foundation

func solution(_ array: [Int]) -> Int {
    let array = array
        .reduce(into: [Int: Int]()) { dic, elem in
            dic[elem, default: 0] += 1
        }
        .sorted { $0.value > $1.value }
    
    if array.count == 1 {
        return array[0].key
    }
    
    if array[0].value == array[1].value {
        return -1
    }
    
    return array[0].key
}
~~~



### 햄버거 만들기

- https://school.programmers.co.kr/learn/courses/30/lessons/133502

~~~swift
import Foundation

func solution(_ ingredient: [Int]) -> Int {
    var stk = [Int]()
    return ingredient.reduce(into: 0) { ans, elem in
        stk.append(elem)
        if stk.count >= 4 && Array(stk[stk.count-4..<stk.count]) == [1, 2, 3, 1] {
            stk.removeSubrange(stk.count-4..<stk.count)
            ans += 1
        }
    }
}
~~~



### 연속된 수의 합

- link : https://school.programmers.co.kr/learn/courses/30/lessons/120923

~~~swift
import Foundation

func solution(_ num: Int, _ total: Int) -> [Int] {
    let baseSum = (1...num).reduce(0, +)
    let diff = (total - baseSum) / num
    let lowerBounds = 1 + diff
    let upperBounds = 1 + diff + num
    return Array(lowerBounds ..< upperBounds)
}
~~~



### 등수 매기기

- link : https://school.programmers.co.kr/learn/courses/30/lessons/120882

~~~swift
import Foundation

func solution(_ score:[[Int]]) -> [Int] {
    let sortedScores = score.sorted { $0[0] + $0[1] > $1[0] + $1[1] }
    var dic = [Int: Int]()
    var (lv, mn) = (0, Int.max)
    sortedScores.forEach {
        lv += 1
        let sum = $0[0] + $0[1]
        if sum < mn {
            mn = sum
            dic[sum] = lv
        }
    }
    
    return score.reduce(into: [Int]()) { ans, list in
        let sum = list[0] + list[1]
        ans.append(dic[sum]!)
    }
}
~~~



### OX퀴즈

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120907?language=swift
  - 문자열 파싱 문제


~~~swift
import Foundation

func solution(_ quiz:[String]) -> [String] {
    return quiz.reduce(into: [String]()) { ans, query in
        let splited = query.split(separator: " ").map(String.init)
        let firstNumber = Int(splited[0])!
        let com = splited[1]
        let secondNumber = Int(splited[2])!
        let thirdNumber = Int(splited[4])!
        switch com {
        case "-":
            ans.append(firstNumber - secondNumber == thirdNumber ? "O" : "X")
        case "+":
            ans.append(firstNumber + secondNumber == thirdNumber ? "O" : "X")
        default:
            break
        }
    }
}
~~~



### 문자열 계산하기

- 문자열 파싱 문제

~~~swift
import Foundation

func solution(_ my_string:String) -> Int {
    let arr = my_string.split(separator: " ").map(String.init)
    var (idx, ans) = (1, Int(arr.first!)!)
    while idx + 1 < arr.count {
        let com = arr[idx]
        let next = Int(arr[idx+1])!
        switch com {
        case "-":
            ans -= next
        case "+":
            ans += next
        default: break
        }
        idx += 2
    }
    return ans
}
~~~



### 외계어 사전

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120869
  - String, Hash


~~~swift
import Foundation

func solution(_ spell:[String], _ dic:[String]) -> Int {
    var spellDic = [Int](repeating: 0, count: 26)
    spell.forEach {
        let ascii = Int(Character($0).asciiValue!) - 97
        spellDic[ascii] += 1
    }
    return dic.reduce(into: 0) { count, str in
        var tempDic = [Int](repeating: 0, count: 26)
        str.forEach { char in
            let ascii = Int(char.asciiValue!) - 97
            tempDic[ascii] += 1
        }
        count += spellDic == tempDic ? 1 : 0
    } > 0 ? 1 : 2
}
~~~



### 안전지대

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120866
  - array, implementation

~~~swift
import Foundation

let dx = [-1, -1, -1, 0, 0, 0, 1, 1, 1]
let dy = [-1, 0, 1, -1, 0, 1, -1, 0, 1]
func solution(_ board: [[Int]]) -> Int {
    var board = board
    var ans = 0
    for i in board.indices {
        for j in board[i].indices {
            let num = board[i][j]
            if num == 0 {
                ans += 1
            } else if num == 1 {
                for k in dx.indices {
                    let nx = i + dx[k]
                    let ny = j + dy[k]
                    if nx < 0 || ny < 0 || nx >= board.count || ny >= board[0].count {
                        continue
                    }
                    if board[nx][ny] != 0 { continue }
                    board[nx][ny] = 2
                    if (0...3) ~= k { ans -= 1 }
                }
            } else if num == 2 {
                continue
            }
        }
    }
    return ans
}
~~~



### 특이한 정렬

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120880
  - sorting with multiple conditions

~~~swift
import Foundation

func solution(_ numlist: [Int], _ n: Int) -> [Int] {
    return numlist.sorted {
        let firstAbs = abs(Double($0-n))
        let secondAbs = abs(Double($1-n))
        if firstAbs != secondAbs { return firstAbs < secondAbs } 
        else { return $0 > $1 }
    }
}
~~~



### 로그인 성공?

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120883

~~~swift
import Foundation

func solution(_ id_pw:[String], _ db:[[String]]) -> String {
    var isValidID = false
    for query in db {
        if id_pw == query { return "login" }
        if id_pw[0] == query[0] { isValidID = true }
    }
    return isValidID ? "wrong pw" : "fail"
}
~~~



### 캐릭터의 좌표

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120861
  - implementation

~~~swift
import Foundation

func solution(_ keyInput: [String], _ board: [Int]) -> [Int] {
    let comDic: [String: (Int, Int)] = ["left": (-1, 0), "right": (1, 0), "up": (0, 1), "down": (0, -1)]
    let (mnX, mxX) = (-(board[0] / 2), board[0] / 2)
    let (mnY, mxY) = (-(board[1] / 2), board[1] / 2)
    return keyInput.reduce(into: [0, 0]) { ans, com in
        let nx = ans[0] + comDic[com]!.0
        let ny = ans[1] + comDic[com]!.1
        if nx < mnX || ny < mnY || nx > mxX || ny > mxY { return }
        ans = [nx, ny]
    }
}
~~~



### 저주의 숫자 3

- https://school.programmers.co.kr/learn/courses/30/lessons/120871
  - Implementation

~~~swift
import Foundation

func solution(_ n:Int) -> Int {
    return (1...n).reduce(into: 0) { ans, _ in
        func isThreeDigit(_ num: Int) -> Bool {
            var (temp, isThree) = (ans, false)
            while temp > 0 {
                if temp % 10 == 3 { return true }
                temp /= 10
            }
            return false
        }
        ans += 1
        while ans % 3 == 0 || isThreeDigit(ans) { ans += 1 }                                 
    }
}
~~~



### 컨트롤 제트

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120853#qna
- Z가 나오면 더한거 빠꾸하고, 숫자 나오면 더하는 문제
  - 빠꾸할때 사용한 숫자는 버리고 그거보다 이전에 더한거부터 빠꾸를 진행해야함

~~~swift
import Foundation

func solution(_ s:String) -> Int {
    var last = 0
    var numList: [Int] = []
    return s.split(separator: " ").map(String.init).reduce(into: 0) { ans, query in
        if query == "Z" { 
            if numList.isEmpty { return }
            ans -= numList.last!
            numList.removeLast()
            return
        }
        let num = Int(query)!
        ans += num
        numList.append(num)
    }
}
~~~

