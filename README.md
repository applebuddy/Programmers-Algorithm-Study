# Programmers-Algorithm-Study
Uploading programmers study source codes for the first time

# 기초 트레이닝

~~~swift
// 가까운 1 찾기
func solution(_ arr: [Int], _ idx: Int) -> Int {
    return arr[idx...].indices.first(where: { arr[$0] == 1 }) ?? -1
}
~~~

~~~swift
// 9로 나눈 나머지
func solution(_ number: String) -> Int {
    return number
        .map { (Int($0.asciiValue!) - 48) }
        .reduce(0, +) % 9
}
~~~

~~~swift
// ad 제거하기
func solution(_ strArr: [String]) -> [String] {
    return strArr.filter { !$0.contains("ad") }
}
~~~

~~~swift
// 배열의 원소 삭제하기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181844
func solution(_ arr: [Int], _ delete_list: [Int]) -> [Int] {
    let set = Set(delete_list)
    return arr.filter { !set.contains($0) }
}
~~~

~~~ swift
// 배열 비교하기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181856
func solution(_ arr1: [Int], _ arr2: [Int]) -> Int {
    if arr1.count > arr2.count { return 1 }
    else if arr1.count < arr2.count { return -1 }
    let sum = arr1.reduce(0, +)
    let sum2 = arr2.reduce(0, +)
    return sum == sum2 ? 0 : (sum > sum2 ? 1 : -1)
}
~~~

~~~swift
// 0 떼기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181847
func solution(_ n_str: String) -> String {
    let arr = Array(n_str).map(String.init)
    let index = arr.indices.first(where: { arr[$0] != "0" })!
    return arr[index...].joined()
}
~~~

~~~swift
// 5명씩
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181886
func solution(_ names: [String]) -> [String] {
    return stride(from: 0, to: names.count, by: 5).map { names[$0] }
}
~~~

~~~swift
// 주사위 게임 2
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181930
func solution(_ a: Int, _ b: Int, _ c: Int) -> Int {
    switch Set([a, b, c]).count {
    case 1: return (a + b + c) * (a * a + b * b + c * c) * (a * a * a + b * b * b + c * c * c)
    case 2: return (a + b + c) * (a * a + b * b + c * c)
    default: return a + b + c
    }
}
~~~

~~~swift
// l로 만들기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181834
func solution(_ myString: String) -> String {
    myString
        .map { $0 < "l" ? "l" : "\($0)" }
        .joined()
}
~~~

~~~swift
// 순서 바꾸기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181891
func solution(_ num_list: [Int], _ n: Int) -> [Int] {
    [Int](num_list[n...] + num_list[..<n])
}
~~~

~~~swift
// 간단한 식 계산하기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181865
func solution(_ binomial: String) -> Int {
    var (opt, first, second) = ("", "", "")
    for char in binomial {
        let s = "\(char)"
        if ["+", "-", "*"].contains(s) { 
            opt = s
            first = second
            second = ""
            continue
        }

        second += s == " " ? "" : s
    }

    switch opt {
    case "+": return Int(first)! + Int(second)!
    case "-": return Int(first)! - Int(second)!
    default: return Int(first)! * Int(second)!
    }
}
~~~

~~~swift
// 접미사 배열
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181909
func solution(_ my_string: String) -> [String] {
    my_string
        .reversed()
        .reduce(into: ("", [String]())) { result, char in
            result.0 = "\(char)\(result.0)"
            result.1.append(result.0)
        }
        .1.sorted()
}
~~~

~~~swift
// 특별한 이차원 배열
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181831
func solution(_ arr: [[Int]]) -> Int {
    for i in arr.indices {
        for j in arr[i].indices {
            if arr[i][j] != arr[j][i] { return 0 }
        }
    }
    return 1
}
~~~

~~~swift
// 공백으로 구분하기 2
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181868
func solution(_ my_string: String) -> [String] {
    return my_string.split(separator: " ").map(String.init)
}
~~~

~~~swift
// 부분 문자열 이어 붙여 문자열 만들기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181911
func solution(_ my_strings: [String], _ parts: [[Int]]) -> String {
    zip(my_strings, parts)
        .reduce(into: "") { ans, tp in
            ans += Array(tp.0)[tp.1[0]...tp.1[1]].map(String.init).joined()
        }
}
~~~

~~~swift
// 뒤에서 5등까지
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181853
func solution(_ num_list: [Int]) -> [Int] {
    Array(num_list.sorted().prefix(5))
}
~~~

~~~swift
// 꼬리 문자열
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181841
func solution(_ str_list: [String], _ ex: String) -> String {
    str_list.filter { !$0.contains(ex) }.joined()
}
~~~

~~~swift
// A 강조하기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181874
func solution(_ myString: String) -> String {
    Array(myString)
        .map(String.init)
        .map { ($0 == "a" || $0 == "A") ? $0.uppercased() : $0.lowercased() }
        .joined()
}
~~~

~~~swift
// 배열의 원소만큼 추가하기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181861
func solution(_ arr: [Int]) -> [Int] {
    arr.flatMap { [Int](repeating: $0, count: $0) }
}
~~~

~~~swift
// 홀수 vs 짝수
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181887
func solution(_ num_list: [Int]) -> Int {
    num_list
        .enumerated()
        .reduce(into: [0, 0]) {
            if $1.offset % 2 == 0 {
                $0[0] += $1.element
            } else {
                $0[1] += $1.element
            }
        }
        .max()!
}
~~~

~~~swift
// 배열에서 문자열 대소문자 변환하기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181875
func solution(_ strArr: [String]) -> [String] {
    strArr
        .enumerated()
        .map { $0.offset % 2 == 0 ? $0.element.lowercased() : $0.element.uppercased() }
}
~~~

~~~swift
// 접미사인지 확인하기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181908
func solution(_ my_string: String, _ is_suffix: String) -> Int {
    my_string.hasSuffix(is_suffix) ? 1 : 0
}
~~~

~~~swift
// 특정한 문자를 대문자로 바꾸기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181873
func solution(_ my_string: String, _ alp: String) -> String {
    my_string.reduce(into: "") { 
        let string = "\($1)"
        $0 += (string == alp ? string.uppercased() : string)
    }
}
~~~

~~~swift
// 글자 이어 붙여 문자열 만들기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181915
func solution(_ my_string: String, _ index_list: [Int]) -> String {
    let arr = Array(my_string)
    return index_list.reduce(into: "") { $0 += "\(arr[$1])" }
}
~~~

~~~swift
// 문자열 바꿔서 찾기
// link : https://school.programmers.co.kr/learn/courses/30/lessons/181864
func solution(_ myString: String, _ pat: String) -> Int {
    myString
        .reduce(into: "") { $0 += ($1 == "A" ? "B" : "A") }
        .contains(pat) ? 1 : 0
}
~~~

~~~swift
// n개 간격의 원소들
// link : https://school.programmers.co.kr/learn/courses/30/lessons/181888
func solution(_ num_list: [Int], _ n: Int) -> [Int] {
    [Int](stride(from: 0, through: num_list.count - 1, by: n))
        .map { num_list[$0] }
}
~~~

~~~swift
// 원하는 문자열 찾기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181878
func solution(_ myString: String, _ pat: String) -> Int {
    return myString.lowercased().contains(pat.lowercased()) ? 1 : 0
}
~~~

~~~swift
// 조건 문자열
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181934
func solution(_ ineq: String, _ eq: String, _ n: Int, _ m: Int) -> Int {
    switch (ineq, eq) {
    case (">", "="): return n >= m ? 1 : 0
    case ("<", "="): return n <= m ? 1 : 0
    case (">", "!"): return n > m ? 1 : 0
    case ("<", "!"): return n < m ? 1 : 0
    default: return 0
    }
}
~~~

~~~swift
// 두 수의 연산 값 비교하기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181938
func solution(_ a: Int, _ b: Int) -> Int {
    let first = Int("\(a)\(b)")!
    let second = 2 * a * b
    return first > second ? first : second
}
~~~


~~~swift
// 문자열 섞기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181942
func solution(_ str1: String, _ str2: String) -> String {
    zip(str1, str2).map { "\($0.0)\($0.1)" }.joined()
}
~~~

~~~swift
// 문자열 겹쳐 쓰기
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181943
func solution(_ my_string: String, _ overwrite_string: String, _ s: Int) -> String {
    let myArray = Array(my_string)
    let otherArray = Array(overwrite_string)
    return myArray
        .enumerated()
        .map {
            guard $0.offset >= s, otherArray.indices ~= ($0.offset - s)
            else { return "\($0.element)" }
            return "\(otherArray[$0.offset - s])"
        }
        .joined()
}
~~~

~~~swift
// 이어 붙인 수
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181928
func solution(_ num_list: [Int]) -> Int {
    return num_list
        .reduce(into: ["", ""]) { tp, num in
            if num % 2 == 0 {
                tp[0] += "\(num)"
            } else {
                tp[1] += "\(num)"
            }
        }
        .map { Int($0)! }
        .reduce(0, +)
}
~~~

~~~swift
// 주사위 게임 1
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181839
func solution(_ a: Int, _ b: Int) -> Int {
    let isOdd: (Int) -> Bool = { $0 % 2 == 1 }
    let (isAOdd, isBOdd) = (isOdd(a), isOdd(b))
    switch (isAOdd, isBOdd) {
    case (true, true): 
        return a * a + b * b
    case (true, false), (false, true): 
        return 2 * (a + b)
    case (false, false):
        return (a - b) * (a >= b ? 1 : -1)
    }
    return 0
}
~~~

~~~swift
// 배열 만들기 1
// - link : https://school.programmers.co.kr/learn/courses/30/lessons/181901
func solution(_ n:Int,_ k:Int)->[Int]{[Int](stride(from: k, through: n, by: k))}
~~~


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



### 치킨 쿠폰

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120884
  - simulation

~~~swift
import Foundation

func solution(_ chicken:Int) -> Int {
    var ans = 0
    var chi = chicken
    while chi >= 10 {
        let bonus = chi / 10
        chi %= 10
        chi += bonus
        ans += bonus
    }
    return ans
}
~~~



### 분수의 덧셈

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120808
  - math

~~~swift
import Foundation

func solution(_ denum1:Int, _ num1:Int, _ denum2:Int, _ num2:Int) -> [Int] {
    var first: [Int] = [denum1*num2, num1*num2]
    var second: [Int] = [denum2*num1, num2*num1]
    var result: [Int] = [first[0]+second[0], first[1]]
    return (1...min(result[0], result[1])).reduce(into: result) { ans, target in
        while (target > 1 && ans[0] % target == 0 && ans[1] % target == 0) {
            ans[0] /= target
            ans[1] /= target
        }
    }
}
~~~



### 평행

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120875#qna
  - math

~~~swift
import Foundation

func solution(_ dots:[[Int]]) -> Int {
    var dic: [Float: Bool] = [:]

    func isParallel(_ first: [Int], _ second: [Int]) -> Bool {
        var diff = Float(second[0] - first[0]) / Float(second[1] - first[1])
        if dic[diff] != nil {
            return true
        }
        dic[diff] = true
        return false
    }
    
    for i in 0 ..< dots.count - 1 {
        for j in i+1 ..< dots.count {
            if isParallel(dots[i], dots[j]) { return 1 }
        }
    }

    return 0
}
~~~



### 옹알이 (2)

- problem link :  https://school.programmers.co.kr/learn/courses/30/lessons/133499?language=swift
  - hash, string

~~~swift
import Foundation

func solution(_ babbling: [String]) -> Int {
    let st = Set<String>(["aya", "ye", "woo", "ma"])
    var last = ""
    var temp  = ""
    return babbling.reduce(into: 0) { ans, query in
        temp = ""
        last = ""
        for char in query {
            temp += "\(char)"
            if st.contains(temp) {
                if temp == last { return }
                last = temp
                temp = ""
            }
        }
        if temp.isEmpty {
            ans += 1
        }
    }
}
~~~



### 삼각형의 완성조건 (2)

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120868

~~~swift
import Foundation

func solution(_ sides: [Int]) -> Int {
    var ans = 0
    let sum = sides[0] + sides[1]
    let mx = max(sides[0], sides[1])
    let mn = min(sides[0], sides[1])
    if mx < sum - 1 {
        ans += sum - mx - 1
    }

    if 0 < sum - mx {
        print(sum - mx)
        ans += sum - mx
    }

    return ans
}
~~~



### 직사각형 넓이 구하기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120860
  - math

~~~swift
import Foundation

func solution(_ dots: [[Int]]) -> Int {
    let mn = dots.min { $0[0] < $1[0] }![0]
    let mx = dots.max { $0[0] < $1[0] }![0]
    let mn2 = dots.min { $0[1] < $1[1] }![1]
    let mx2 = dots.max { $0[1] < $1[1] }![1]
    return (mx - mn) * (mx2 - mn2)
}
~~~



### 다항식 더하기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120863#qna
  - string

~~~swift
import Foundation

func solution(_ polynomial:String) -> String {
    let arr = polynomial.split(separator: " ").map(String.init)
    let nums = arr.filter { $0.last! != "x" && $0.last! != "+" }.compactMap(Int.init).reduce(0, +)
    
    let xNums = arr.filter { $0.last! == "x" }.reduce(into: 0) { nums, xn in
        if xn == "x" { nums += 1 }
        else {
            var txn = xn.dropLast()
            nums += Int(txn)!
        }
    }

    var ans = ""
    if xNums > 0 { ans += xNums == 1 ? "x" : "\(xNums)x" }
    if nums > 0 { ans += (!ans.isEmpty ? " + " : "") + "\(nums)" }
    return ans
}
~~~



### 소인수분해

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120852
  - math, 에라토스테네스의 체

~~~swift
import Foundation

func solution(_ n:Int) -> [Int] {
    var prime = [Bool](repeating: true, count: n+1)
    prime[0...1] = [false, false]
    var i = 2, j = i + i
    if n == 2 { return [2] }
    while i * i <= n {
        j = i + i
        while j <= n {
            prime[j] = false
            j += i
        }
        i += 1
    }
    var num = n
    return prime
        .enumerated()
        .filter { $0.1 }
        .map { $0.0 }
        .reduce(into: [Int]()) { ans, prime in
            var valid = false
            while num % prime == 0 {
                num /= prime
                valid = true
            }        
            if valid { ans.append(prime) }
        }
}
~~~



### 숨어있는 숫자의 덧셈 (2)

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120864#

~~~swift
import Foundation

func solution(_ my_string: String) -> Int {
    var temp = 0
    return my_string.reduce(into: 0) { ans, char in
        let ascii = Int(char.asciiValue!) - 48
        guard (0...9) ~= ascii else { 
            ans += temp
            temp = 0
            return 
        }
        temp = temp * 10 + ascii
    } + temp
}
~~~



### 모스부호 (1)

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120838
  - hash, string

~~~swift
import Foundation

func solution(_ letter:String) -> String {
    let dic = [
      ".-":"a","-...":"b","-.-.":"c","-..":"d",".":"e","..-.":"f", "--.":"g",
      "....":"h","..":"i",".---":"j","-.-":"k",".-..":"l", "--":"m","-.":"n",
      "---":"o",".--.":"p","--.-":"q",".-.":"r", "...":"s","-":"t","..-":"u",
      "...-":"v",".--":"w","-..-":"x", "-.--":"y","--..":"z"
    ]
    var temp = ""    
    return letter.split(separator: " ").reduce(into: "") { ans, char in
        temp += "\(char)"
        if let value = dic[temp] {
            ans += value
            temp = ""
        }
    }
}
~~~



### 종이 자르기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120922

~~~swift
import Foundation

func solution(_ M:Int, _ N:Int) -> Int {
    return N * M - 1 // 1x1 단위로 잘개 자르기 위해 필요한 가위질 횟수 공식.
}
~~~



### 유한소수 판별하기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120878
  - math

~~~swift
import Foundation

func solution(_ a:Int, _ b:Int) -> Int {
    var first = a, second = b
    let mx = max(a, b)
    let mn = min(a, b)
    (1...mn).forEach {
        while $0 > 1 && first % $0 == 0 && second % $0 == 0 {
            first /= $0
            second /= $0
        }
    }
    
    for num in (1...second) {
        while num > 1 && second % num == 0 {
            if !(num == 2 || num == 5) {
                return 2
            }
            second /= num
        }
    }
    return 1
}
~~~



### 구슬을 나누는 경우의 수

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/120840
  - math, combination

~~~swift
import Foundation

func solution(_ balls: Int, _ share: Int) -> Int {
    var dic = ((balls - share + 1) ... balls).reduce(into: [Int: Bool]()) { dic, num in
        dic[num] = true
    }
    
    var additionalNumberList = [Int]()
    (1...share).forEach {
        if dic[$0] != nil {
            dic[$0] = nil   
        } else {
            additionalNumberList.append($0)
        }
    }
    
    var idx = 0
    return dic.reduce(into: 1) { 
        $0 *= $1.key 
        while idx < additionalNumberList.count && $0 % additionalNumberList[idx] == 0 {
            $0 /= additionalNumberList[idx]
            idx += 1
        } 
    }
}
~~~



# Level 1

### 개인정보 수집 유효기간 (K)

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/150370
- math, string

~~~swift
import Foundation

extension Array where Element == Int {
    var date: String {
        return String(format: "%02d", self[0]) + 
               String(format: ".%02d", self[1]) + 
               String(format: ".%02d", self[2])
    }
    
    mutating func addMonth(_ month: Int) {
        self[0] += (month + self[1]) / 12
        self[1] = (month + self[1]) % 12
        if self[1] == 0 {
            self[0] -= 1
            self[1] = 12
        }
    }
    
    mutating func minusDate() {
        if self[2] == 1 {
            self[1] -= 1
            self[2] = 28
            if self[1] == 0 {
                self[0] -= 1
                self[1] = 12
            }
        } else {
            self[2] -= 1
        }
    }
}

func solution(_ today: String, _ terms: [String], _ privacies: [String]) -> [Int] {
    let now = today.split(separator: ".").map { Int(String($0))! }
    let dic = terms.reduce(into: [String: Int]()) {
        let term = $1.split(separator: " ").map(String.init)
        $0[term[0]] = Int(term[1])!
    }
    return privacies.enumerated().reduce(into: [Int]()) { result, tuple in 
        let (i, p) = tuple
        let arr = p.split(separator: " ").map(String.init)
        var pDate = arr[0].split(separator: ".").map { Int(String($0))! }
        let key = arr[1]
        let month = dic[key]!            
        pDate.addMonth(month)
        pDate.minusDate()
        if now.date > pDate.date { result.append(i + 1) }
    }
}
~~~

### 추억 점수

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/176963?language=swift
- hash

~~~swift
import Foundation

func solution(_ name:[String], _ yearning:[Int], _ photo:[[String]]) -> [Int] {
    let dic = [String: Int](uniqueKeysWithValues: zip(name, yearning))
    return photo.map { ps in
        return ps.reduce(into: 0) { $0 += dic[$1, default: 0] }
    }
}
~~~

### 달리기 경주

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/178871
- hash

~~~swift
import Foundation

func solution(_ players: [String], _ callings: [String]) -> [String] {
    var ps = players
    var dic = ps.enumerated().reduce(into: [String: Int]()) { $0[$1.element] = $1.offset }
    return callings.reduce(into: ps) { result, calling in
        let idx = dic[calling]!
        dic[calling]! -= 1
        dic[result[idx-1]]! += 1
        result.swapAt(idx, idx-1)
    }
}
~~~


### 공원 산책

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/172928
- simulation

~~~swift
import Foundation

let dx = [0, 1, 0, -1]
let dy = [1, 0, -1, 0]

func solution(_ park: [String], _ routes: [String]) -> [Int] {
    var pos = (0, 0)
    let G = park.enumerated().reduce(into: [[String]]()) { result, tuple in
        let (i, string) = tuple
        let array = string.enumerated().reduce(into: [String]()) { result2, tuple2 in
            let (j, char) = tuple2
            if char == "S" { pos = (i, j) }
            result2.append("\(char)")
        }
        result.append(array)
    }
    let row = G.count
    let col = G[0].count
    return routes.reduce(into: [pos.0, pos.1]) { result, route in
        let array = route.split(separator: " ").map { String($0) }
        let dir = array[0]
        let dist = Int(array[1])!
        var ddx = 0
        switch dir {
        case "E":
            ddx = 0
        case "S":
            ddx = 1
        case "W":
            ddx = 2
        case "N":
            ddx = 3
        default: break
        }
        var isPossible = true
        var nx = result[0]
        var ny = result[1]
        for _ in 0..<dist {
            nx += dx[ddx]
            ny += dy[ddx]
            if nx < 0 || ny < 0 || nx >= row || ny >= col || G[nx][ny] == "X" { 
                isPossible = false
                break 
            }
        }
        if isPossible { 
            result = [nx, ny]
        }
    }
}
~~~





### 기사단원의 무기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/136798
- math

~~~swift
import Foundation

func solution(_ number: Int, _ limit: Int, _ power: Int) -> Int {
    return (1...number).reduce(into: 0) { result, n in
        var (i, count) = (1, 0)
        while i * i <= n {
            if n % i == 0 {
                count += 1 
                if i * i < n {
                    count += 1
                }
            }
            i += 1
        }
        result += count <= limit ? count : power
    }
}
~~~





### 푸드 파이트 대회

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/134240
- math

~~~swift
import Foundation

func solution(_ food: [Int]) -> String {
    var s: [String] = []
    food.enumerated().forEach { tuple in
        let (i, n) = tuple
        let cnt = n / 2
        if cnt > 0 {
            s += [String](repeating: "\(i)", count: cnt)
        }
    }
    return (s + ["0"] + s.reversed()).joined()
}
~~~





### 바탕화면 정리

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/161990
- math

~~~swift
import Foundation

func solution(_ wallpaper: [String]) -> [Int] {
    var min = (Int.max, Int.max)
    var max = (0, 0)
    wallpaper.enumerated().map { tuple in
        let (i, string) = tuple
        Array(string).enumerated().forEach { tuple2 in
            let (j, char) = tuple2
            if char == "#" {
                min.0 = min.0 > i ? i : min.0
                min.1 = min.1 > j ? j : min.1
                max.0 = max.0 < i ? i : max.0
                max.1 = max.1 < j ? j : max.1
            }
        }
    }
    return [min.0, min.1, max.0+1, max.1+1]
}
~~~





### 카드 뭉치

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/159994
- simulation

~~~swift
import Foundation

func solution(_ cards1: [String], _ cards2: [String], _ goal: [String]) -> String {
    var (i, j) = (0, 0)
    for s in goal {
        if cards1.indices ~= i, cards1[i] == s {
            i += 1
        } else if cards2.indices ~= j, cards2[j] == s {
            j += 1
        } else { return "No" }
    }
    return "Yes"
}
~~~



### 대충 만든 자판

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/160586
- simulation

~~~swift
import Foundation

func solution(_ keymap: [String], _ targets: [String]) -> [Int] {
    let dic = keymap.reduce(into: [Character: Int]()) { result, key in
        key.enumerated().forEach { index, char in
            if result[char] != nil {
                result[char] = min(result[char]!, index + 1)
            } else {
                result[char] = index + 1
            }
        }
    }
    
    var ans: [Int] = []
    for target in targets {
        var count = 0
        for char in target {
            if dic[char] == nil { count = -1; break }
            count += dic[char]!
        }
        ans.append(count == -1 ? -1 : count)   
    }
    return ans
}
~~~





### 둘만의 암호

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/155652
- String

~~~swift
import Foundation

func solution(_ s: String, _ skip: String, _ index: Int) -> String {
    let dic = skip.reduce(into: [Bool](repeating: false, count: 27)) { arr, char in
        let ascii = Int(char.asciiValue!) - 97
        arr[ascii] = true
    }
    return s.reduce(into: "") { result, char in
        var ascii = Int(char.asciiValue!) - 97
        var count = 0
        while count < index {
            ascii = (ascii + 1) % 26
            if dic[ascii] { continue }
            count += 1
        }
        result += "\(Character(Unicode.Scalar(ascii + 97)!))"
    }
}
~~~





### 크기가 작은 부분 문자열
- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/147355

- string

~~~swift
import Foundation

func solution(_ t: String, _ p: String) -> Int {
    let tArray = Array(t).map(String.init)
    let pArray = Array(p).map(String.init)
    let tCount = tArray.count
    let pCount = pArray.count
    let pString = pArray.joined()
    var ans = 0
    for index in 0...(tCount-pCount) {
        let subString = tArray[index..<index+pCount].joined()
        ans += pString >= subString ? 1 : 0
    }
    return ans
}
~~~



### 가장 가까운 같은 글자

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/142086
- dictionary, string

~~~swift
import Foundation

func solution(_ s: String) -> [Int] {
    var dic = [Int](repeating: -1, count: 27)
    return s.enumerated().reduce(into: [Int]()) { result, tuple in
        let index = tuple.offset
        let char = tuple.element
        let ascii = Int(char.asciiValue!) - 97
        if dic[ascii] != -1 {
            result.append(index - dic[ascii])
        } else {
            result.append(-1)
        }
        dic[ascii] = index
    }
}
~~~



### 콜라 문제

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/132267?language=swift
- math

~~~swift
import Foundation

func solution(_ a: Int, _ b: Int, _ n: Int) -> Int {
    var (have, ans) = (n, 0)
    while have >= a {
        let bonus = (have / a) * b
        ans += bonus
        have %= a
        have += bonus
    }
    return ans
}
~~~





### 과일 장수

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/135808
- sorting

~~~swift
import Foundation

func solution(_ k:Int, _ m:Int, _ score:[Int]) -> Int {
    var mn = Int.max
    return score.sorted(by: >).enumerated().reduce(into: 0) { ans, tuple in
        let (idx, num) = (tuple.0, tuple.1)
        mn = mn > num ? num : mn
        if idx % m == m - 1 {
            ans += mn * m
            mn = Int.max
        }
    }
}
~~~



### 최소직사각형

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/86491
- 모든 명함을 수용 가능한 가장 최소 크기의 지값 넓이 구하기
- sorting

~~~swift
import Foundation

func solution(_ sizes:[[Int]]) -> Int {
    var mx = [0, 0]
    for i in sizes.indices {
        var size = sizes[i]
        if size[0] < size[1] {
            size.swapAt(0, 1)
        }
        mx[0] = mx[0] < size[0] ? size[0] : mx[0]
        mx[1] = mx[1] < size[1] ? size[1] : mx[1]
    }
    return mx.reduce(1, *)
}
~~~



### 문자열 나누기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/140108

- string

~~~swift
import Foundation

func solution(_ s: String) -> Int {
    var (l, r) = (0, 0)
    var first = ""
    var ans = 0
    for char in s {
        if first.isEmpty {
            first = "\(char)"
            l = 1
            continue
        }

        if "\(char)" == first { l += 1 }
        else { r += 1 }
        if l == r { 
            ans += 1
            l = 0
            r = 0
            first = ""
        }
    }
    ans += l + r > 0 ? 1 : 0
    return ans
}
~~~



### 명예의 전당(1)

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/138477

- binary-search, sorting

~~~swift
import Foundation

extension Array where Element == Int {
   mutating func binaryInsert(_ num: Int) {
        if self.isEmpty { self.append(num); return }
        var left = 0
        var right = self.count-1
        while left <= right {
            let mid = (left + right) / 2
            if self[mid] < num {
                left = mid + 1
            } else {
                right = mid - 1
            }
        }
        self.insert(num, at: left)
    }
}

func solution(_ k: Int, _ score: [Int]) -> [Int] {
    var (ans, arr) = ([Int](), [Int]())
    return score.reduce(into: (ans, arr)) { (tuple, num) in 
        tuple.1.binaryInsert(num)
        tuple.0 += [tuple.1[tuple.1.count <= k ? 0 : tuple.1.count-k]]
    }.0
}
~~~


### 성격 유형 검사하기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/118666
  - hash

~~~swift
import Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    let dic = survey.enumerated().reduce(into: [String: Int]()) { (result, tuple) in
        let arr = Array(tuple.element).map(String.init)
        let first = arr[0]
        let second = arr[1]
        let val = choices[tuple.offset] - 4
        result[val > 0 ? second : first, default: 0] += val > 0 ? val : -val
    }
    let (R, T) = (dic["R", default: 0], dic["T", default: 0])
    let (C, F) = (dic["C", default: 0], dic["F", default: 0])
    let (J, M) = (dic["J", default: 0], dic["M", default: 0])
    let (A, N) = (dic["A", default: 0], dic["N", default: 0])
    let one = R >= T ? "R" : "T"
    let two = C >= F ? "C" : "F"
    let three = J >= M ? "J" : "M"
    let four = A >= N ? "A" : "N"
    return one + two + three + four
}
~~~



### 없는 숫자 더하기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/86051
  - hash set

~~~swift
import Foundation

func solution(_ numbers: [Int]) -> Int {
    // subtracting, symmetricDifference 둘 다 가능
    return Set(1...9).symmetricDifference(Set(numbers)).reduce(0, +)
}
~~~



### 숫자 짝꿍

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/131128
  - hash

~~~swift
import Foundation

func solution(_ X:String, _ Y:String) -> String {
    var xDic = [Int: Int]()
    var yDic = [Int: Int]()
    X.forEach { char in 
        let x = Int(char.asciiValue!) - 48
        xDic[x % 10, default: 0] += 1  
    }
    Y.forEach { char in 
        let y = Int(char.asciiValue!) - 48
        yDic[y % 10, default: 0] += 1
    }

    var ans = ""
    var isDup = false
    for num in stride(from: 9, through: 0, by: -1) {
        let count = min(xDic[num, default: 0], yDic[num, default: 0])
        if num != 0 || (num == 0 && (!ans.isEmpty && ans.first! != "0")) {
            ans += String(repeating: "\(num)", count: count)     
        } 
        if count >= 1 { isDup = true }
    }

    return isDup ? (ans.isEmpty ? "0" : ans) : "-1"
}
~~~



### 나머지가 1이 되는 수 찾기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/87389

~~~swift
import Foundation

func solution(_ n:Int) -> Int {
    return (2...n-1).first { n % $0 == 1 }!
}
~~~



### 2개 이하로 다른 비트

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/77885
- bit calculation

~~~swift
import Foundation

func solution(_ numbers: [Int64]) -> [Int64] {
    return numbers.reduce(into: [Int64]()) { ans, num in
        if num % 2 == 0 {
            ans.append(num + 1)
            return
        }
                                      
        var bitArray = ["0"] + Array(String(num, radix: 2)).map(String.init)
        var idx = bitArray.count - 1
        var val = 1
        while idx >= 0 {
            if bitArray[idx] == "0" { bitArray[idx] = "1"; break }
            idx -= 1
            val *= 2
        }
        ans.append(Int64(Int(bitArray.joined(), radix: 2)!) - Int64(val / 2))
    }
}
~~~



### 숫자 카드 나누기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/135807
  - math(gcd)

~~~swift
import Foundation

func gcd(_ a: Int, _ b: Int) -> Int {
    if b == 0 { return a }
    return gcd(b, a % b)
}

func solution(_ arrayA:[Int], _ arrayB:[Int]) -> Int {
    var ans = 0
    var gcdA = arrayA.first!
    if arrayA.count > 1 {
        arrayA[1...].forEach {
            gcdA = gcd(gcdA, $0)
        }
    }
    
    if gcdA > 1 && arrayB.filter({ $0 % gcdA == 0 }).isEmpty {
        ans = gcdA
    }

    var gcdB = arrayB.first!
    if arrayB.count > 1 {
        arrayB[1...].forEach {
            gcdB = gcd(gcdB, $0)
        }
    }
    
    if gcdB > 1 && arrayA.filter({ $0 % gcdB == 0 }).isEmpty {
        ans = ans < gcdB ? gcdB : ans
    }
    
    return ans
}
~~~



# Level 2

### 연속된 부분 수열의 합

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/178870
- two pointer

~~~swift
import Foundation

func solution(_ sequence: [Int], _ k: Int) -> [Int] {
    var (l, r) = (0, -1)
    var sum = 0
    var min = Int.max
    var ans: [Int] = []
    var prev: [Int] = []

    func compare(_ a: Int, _ b: Int) {
        let diff = b - a
        if min > diff {
            min = diff
            ans = [a, b]
        }
    }
 
    while r < sequence.count {
        while sum <= k, r < sequence.count {
            r += 1
            if r >= sequence.count { break }
            sum += sequence[r]
            if sum == k {
                compare(l, r)
                break
            }
        }

        if r >= sequence.count { break }
        while sum >= k, l < r {
            sum -= sequence[l]
            l += 1
            if sum == k {
                compare(l, r)
                break
            }
        }
        if prev == [l, r] { 
            r += 1
        }
        prev = [l, r]
    }
    return ans
}
~~~

### 리코쳇 로봇

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/169199
- BFS

~~~swift
import Foundation

let dx = [1, -1, 0, 0]
let dy = [0, 0, -1, 1]

func solution(_ board: [String]) -> Int {
    var sPos = (0, 0)
    let G = board.enumerated().map { tuple -> [String] in
        let (i, array) = tuple
        return Array(array).enumerated().map { tuple2 in
            let (j, char) = tuple2
            if char == "R" {
                sPos = (i, j)
            }
            return "\(char)"
        }
    }
    var C = [[Bool]](repeating: [Bool](repeating: false, count: G[0].count), count: G.count)
    C[sPos.0][sPos.1] = true
    var cur = 0
    var Q: [(Int, Int, Int)] = [(sPos.0, sPos.1, 0)]
    while cur < Q.count {
        let tuple = Q[cur]
        let (x, y, dist) = tuple
        cur += 1
        for i in dx.indices {
            var (nx, ny) = (x, y)
            var (tx, ty) = (x, y)
            while true {
                tx += dx[i]
                ty += dy[i]
                if tx < 0 || ty < 0 || tx >= G.count || ty >= G[0].count { break }
                if G[tx][ty] == "D" { break }
                nx = tx
                ny = ty
            }
            if C[nx][ny] { continue }
            if G[nx][ny] == "G" { return dist+1 }
            C[nx][ny] = true
            Q.append((nx, ny, dist+1))
        }
    }
    return -1
}
~~~





### 덧칠하기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/161989
- greedy

~~~swift
import Foundation

func solution(_ n: Int, _ m: Int, _ section: [Int]) -> Int {
    var r = 0       
    return section.reduce(into: 0) { result, n in
        if r >= n { return }
        r = n + m - 1
        result += 1
        if r >= section.last! { return }
    }
}
~~~





### 우박수열 정적분

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/134239
- math

~~~swift
import Foundation

func solution(_ k: Int, _ ranges: [[Int]]) -> [Double] {
    var areas: [Double] = []
    var num = k
    var prev = k
    var set: Set<Int> = []
    while true {
        if num % 2 == 0 { num /= 2 }
        else { num = num * 3 + 1 }
        if num <= 1 || set.contains(num) { break }
        set.insert(num)
        let area = Double(prev + num) / 2.0
        areas.append(area)
        prev = num
    }
    let area = Double(prev + 1) / 2.0
    areas.append(area)

    let sums = areas.reduce(into: [Double]()) { result, area in
        if result.isEmpty {
            result.append(area)
        } else {
            result.append(result.last! + area)
        }
    }
    let sumsLen = sums.count
    return ranges.reduce(into: [Double]()) { result, range in
        let (s, e) = (range[0], sumsLen + range[1] - 1)
        if range[0] - range[1] == sumsLen { result.append(0) }
        else if s > e { result.append(-1) }
        else {
            var sum = sums[e]
            if s > 0 {
                sum -= sums[s-1]
            }
            result.append(sum)
        }
    }
}
~~~





### 디펜스 게임

- problem link : 
- heap

~~~swift
// Heap Data Structure 활용, 통과 예시
import Foundation

/// reference : https://github.com/kodecocodes/swift-algorithm-club/blob/master/Heap/Heap.swift
public struct Heap<T> {
  
  /** The array that stores the heap's nodes. */
  var nodes = [T]()
  
  /**
   * Determines how to compare two nodes in the heap.
   * Use '>' for a max-heap or '<' for a min-heap,
   * or provide a comparing method if the heap is made
   * of custom elements, for example tuples.
   */
  private var orderCriteria: (T, T) -> Bool
  
  /**
   * Creates an empty heap.
   * The sort function determines whether this is a min-heap or max-heap.
   * For comparable data types, > makes a max-heap, < makes a min-heap.
   */
  public init(sort: @escaping (T, T) -> Bool) {
    self.orderCriteria = sort
  }
  
  /**
   * Creates a heap from an array. The order of the array does not matter;
   * the elements are inserted into the heap in the order determined by the
   * sort function. For comparable data types, '>' makes a max-heap,
   * '<' makes a min-heap.
   */
  public init(array: [T], sort: @escaping (T, T) -> Bool) {
    self.orderCriteria = sort
    configureHeap(from: array)
  }
  
  /**
   * Configures the max-heap or min-heap from an array, in a bottom-up manner.
   * Performance: This runs pretty much in O(n).
   */
  private mutating func configureHeap(from array: [T]) {
    nodes = array
    for i in stride(from: (nodes.count/2-1), through: 0, by: -1) {
      shiftDown(i)
    }
  }
  
  public var isEmpty: Bool {
    return nodes.isEmpty
  }
  
  public var count: Int {
    return nodes.count
  }
  
  /**
   * Returns the index of the parent of the element at index i.
   * The element at index 0 is the root of the tree and has no parent.
   */
  @inline(__always) internal func parentIndex(ofIndex i: Int) -> Int {
    return (i - 1) / 2
  }
  
  /**
   * Returns the index of the left child of the element at index i.
   * Note that this index can be greater than the heap size, in which case
   * there is no left child.
   */
  @inline(__always) internal func leftChildIndex(ofIndex i: Int) -> Int {
    return 2*i + 1
  }
  
  /**
   * Returns the index of the right child of the element at index i.
   * Note that this index can be greater than the heap size, in which case
   * there is no right child.
   */
  @inline(__always) internal func rightChildIndex(ofIndex i: Int) -> Int {
    return 2*i + 2
  }
  
  /**
   * Returns the maximum value in the heap (for a max-heap) or the minimum
   * value (for a min-heap).
   */
  public func peek() -> T? {
    return nodes.first
  }
  
  /**
   * Adds a new value to the heap. This reorders the heap so that the max-heap
   * or min-heap property still holds. Performance: O(log n).
   */
  public mutating func insert(_ value: T) {
    nodes.append(value)
    shiftUp(nodes.count - 1)
  }
  
  /**
   * Adds a sequence of values to the heap. This reorders the heap so that
   * the max-heap or min-heap property still holds. Performance: O(log n).
   */
  public mutating func insert<S: Sequence>(_ sequence: S) where S.Iterator.Element == T {
    for value in sequence {
      insert(value)
    }
  }
  
  /**
   * Allows you to change an element. This reorders the heap so that
   * the max-heap or min-heap property still holds.
   */
  public mutating func replace(index i: Int, value: T) {
    guard i < nodes.count else { return }
    
    remove(at: i)
    insert(value)
  }
  
  /**
   * Removes the root node from the heap. For a max-heap, this is the maximum
   * value; for a min-heap it is the minimum value. Performance: O(log n).
   */
  @discardableResult public mutating func remove() -> T? {
    guard !nodes.isEmpty else { return nil }
    
    if nodes.count == 1 {
      return nodes.removeLast()
    } else {
      // Use the last node to replace the first one, then fix the heap by
      // shifting this new first node into its proper position.
      let value = nodes[0]
      nodes[0] = nodes.removeLast()
      shiftDown(0)
      return value
    }
  }
  
  /**
   * Removes an arbitrary node from the heap. Performance: O(log n).
   * Note that you need to know the node's index.
   */
  @discardableResult public mutating func remove(at index: Int) -> T? {
    guard index < nodes.count else { return nil }
    
    let size = nodes.count - 1
    if index != size {
      nodes.swapAt(index, size)
      shiftDown(from: index, until: size)
      shiftUp(index)
    }
    return nodes.removeLast()
  }
  
  /**
   * Takes a child node and looks at its parents; if a parent is not larger
   * (max-heap) or not smaller (min-heap) than the child, we exchange them.
   */
  internal mutating func shiftUp(_ index: Int) {
    var childIndex = index
    let child = nodes[childIndex]
    var parentIndex = self.parentIndex(ofIndex: childIndex)
    
    while childIndex > 0 && orderCriteria(child, nodes[parentIndex]) {
      nodes[childIndex] = nodes[parentIndex]
      childIndex = parentIndex
      parentIndex = self.parentIndex(ofIndex: childIndex)
    }
    
    nodes[childIndex] = child
  }
  
  /**
   * Looks at a parent node and makes sure it is still larger (max-heap) or
   * smaller (min-heap) than its childeren.
   */
  internal mutating func shiftDown(from index: Int, until endIndex: Int) {
    let leftChildIndex = self.leftChildIndex(ofIndex: index)
    let rightChildIndex = leftChildIndex + 1
    
    // Figure out which comes first if we order them by the sort function:
    // the parent, the left child, or the right child. If the parent comes
    // first, we're done. If not, that element is out-of-place and we make
    // it "float down" the tree until the heap property is restored.
    var first = index
    if leftChildIndex < endIndex && orderCriteria(nodes[leftChildIndex], nodes[first]) {
      first = leftChildIndex
    }
    if rightChildIndex < endIndex && orderCriteria(nodes[rightChildIndex], nodes[first]) {
      first = rightChildIndex
    }
    if first == index { return }
    
    nodes.swapAt(index, first)
    shiftDown(from: first, until: endIndex)
  }
  
  internal mutating func shiftDown(_ index: Int) {
    shiftDown(from: index, until: nodes.count)
  }
  
}

func solution(_ n: Int, _ k: Int, _ enemy: [Int]) -> Int {
    var heap = Heap<Int> { $0 > $1 }
    var N = n
    var K = k
    let len = enemy.count
    var ans = 0
    for i in enemy.indices {
        if len - i <= K { return len }
        let e = enemy[i]
        if N >= e {
            N -= e
            heap.insert(e)
        } else {
            if K <= 0 { break }
            N -= e
            heap.insert(e)
            while K > 0 && N < 0 {
                if heap.isEmpty { 
                    K -= 1
                    break
                }
                K -= 1
                N += heap.remove()!
            }
            if N < 0 { break }
        }
        ans += 1
    }
    return ans
}
~~~



~~~swift
// case 10 하나가 시간초과 나는 코드 (이진탐색삽입 활용)
import Foundation

extension Array where Element == Int {
    mutating func binaryInsert(_ num: Int) {
        if self.isEmpty { self.append(num); return }
        var left = 0
        var right = self.count - 1
        while left <= right {
            let mid = (left + right) / 2
            if num > self[mid] {
                left = mid + 1
            } else {
                right = mid - 1
            }
        }
        self.insert(num, at: left)
    }
}

func solution(_ n: Int, _ k: Int, _ enemy: [Int]) -> Int {
    var N = n
    var K = k
    var array: [Int] = []
    let len = enemy.count
    var ans = 0
    for i in enemy.indices {
        if len - i <= K { return len }
        let e = enemy[i]
        if N >= e {
            N -= e
            array.binaryInsert(e)
        } else {
            if K <= 0 { break }
            N -= e
            array.binaryInsert(e)
            while K > 0 && N < 0 {
                if array.isEmpty { 
                    K -= 1
                    break
                }
                K -= 1
                N += array.removeLast()
            }
            if N < 0 { break }
        }
        ans += 1
    }
    return ans
}
~~~





### 택배 배달과 수거하기 (K)

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/150369
- Greedy

~~~swift
import Foundation

func solution(_ cap: Int, _ n: Int, _ deliveries: [Int], _ pickups: [Int]) -> Int64 {
    var (d, p) = (0, 0)
    return zip(deliveries, pickups)
        .enumerated()
        .reversed()
        .reduce(into: 0) { result, tuple in
            let (i, (del, pic)) = tuple
            d -= del
            p -= pic
            var cnt = 0
            while d < 0 || p < 0 {
                d += cap
                p += cap
                cnt += 1
            }
            result += Int64((i + 1) * 2 * cnt)
        }
}
~~~





### 미로 탈출

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/159993
- BFS(Breadth-First Search)

~~~swift
import Foundation

func solution(_ maps: [String]) -> Int {
    typealias Pos = (x: Int, y: Int)
    var graph = maps.reduce(into: [[String]]()) { result, map in
        result.append(Array(map).map(String.init))
    }
    
    var sPos: Pos = (0, 0)
    var lPos: Pos = (0, 0)
    var ePos: Pos = (0, 0)
    
    for i in graph.indices {
        for j in graph[0].indices {
            if graph[i][j] == "S" { sPos = (i, j) }
            else if graph[i][j] == "L" { lPos = (i, j) }
            else if graph[i][j] == "E" { ePos = (i, j) }
        }
    }
    
    let col = graph[0].count
    let row = graph.count
    var Chk = [[Bool]](repeating: [Bool](repeating: false, count: col), count: row)
    let dx = [0, 0, 1, -1]
    let dy = [-1, 1, 0, 0]
    
    func bfs(_ from: Pos, _ to: Pos) -> Int {
        var chk = Chk
        chk[from.0][from.1] = true
        var queue: [[Int]] = [[from.0, from.1, 0]]
        var cur = 0
        while cur < queue.count {
            let now = queue[cur]
            let x = now[0]
            let y = now[1]
            let dist = now[2]
            cur += 1
            for i in dx.indices {
                let nx = x + dx[i]
                let ny = y + dy[i]
                if nx < 0 || ny < 0 || nx >= row || ny >= col { continue }
                if chk[nx][ny] || graph[nx][ny] == "X" { continue }
                chk[nx][ny] = true
                if nx == to.0 && ny == to.1 { return dist + 1 }
                queue.append([nx, ny, dist+1])
            }
        }
        return -1
    }
    
    let dist = bfs(sPos, lPos)
    let dist2 = bfs(lPos, ePos)
    
    if dist == -1 || dist2 == -1 { return -1 }
    return dist + dist2
}
~~~





### k진수에서 소수 개수 구하기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/92335
- string, math

~~~swift
import Foundation

extension Int {
    var isPrime: Bool {
        if self < 2 { return false }
        var i = 2
        while i * i <= self {
            if self % i == 0 { return false }
            i += 1
        }
        return true
    }
}

func solution(_ n: Int, _ k: Int) -> Int {
    let string = String(n, radix: k)
    return string.split(separator: "0").reduce(into: 0) {
        $0 += Int(String($1))?.isPrime == true ? 1 : 0
    }
}
~~~



### 모음 사전

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/84512
- bruteForce

~~~swift
import Foundation

func solution(_ word:String) -> Int {
    let target = Array(word).map(String.init)
    var now = ["A"]
    var count = 1
    
    func increase() {
        switch now.last! {
            case "A": 
                now.removeLast()
                now.append("E")
            case "E": 
                now.removeLast()
                now.append("I")
            case "I":
                now.removeLast()
                now.append("O")
            case "O": 
                now.removeLast()
                now.append("U")
            default:
                return
        }
    }

    while true {
        defer {
            // print("now : \(now), count : \(count)")
        }

        if now == target { return count }
        if now.count < 5 {
            now.append("A")
            count += 1
            continue
        }
        
        switch now.last! {
            case "A", "E", "I", "O": 
                increase()
            case "U":
                now.removeLast()
                while now.isEmpty == false && now.last == "U" {
                    now.removeLast()
                }
                increase()
            default: continue
        }
        count += 1
    }
    return count
}
~~~

### 점 찍기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/140107
- mathematics

~~~swift
import Foundation

func solution(_ k: Int, _ d: Int) -> Int64 {
    // 원의 방정식 참고하여 1사분면에 있는 좌표의 갯수를 계산
    func circleEquation(_ x: Int) -> Int {
        return Int(sqrt(Double(d * d - x * x)))
    }
    
    var x = 0
    var ans = 0
    while x <= d {
        defer { x += k }
        let y = circleEquation(x)
        ans += y / k + 1
    }
    
    return Int64(ans)
}
~~~



### N^2 배열 자르기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/87390
- mathematics

~~~swift
import Foundation

func solution(_ n: Int, _ left: Int64, _ right: Int64) -> [Int] {
    (left...right).map { max(Int($0)/n, Int($0)%n) + 1 }
}
~~~



### 호텔 대실

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/155651

- hash

~~~swift
// hash말고 다른 방식은?

import Foundation

extension Character {
    var number: Int {
        return Int(self.asciiValue!) - 48
    }
}

extension String {
    var timeValue: Int {
        let array = Array(self)
        let first = (array[0].number * 10 + array[1].number) * 60
        let second = array[3].number * 10 + array[4].number
        return first + second
    }
}

var timeTable: [Int: Int] = [:]

func solution(_ book_time: [[String]]) -> Int {
    var ans = 0
    book_time.forEach { time in
        (time[0].timeValue...(time[1].timeValue+9)).forEach { value in
           timeTable[value, default: 0] += 1
           let count = timeTable[value, default: 0]
           ans = ans < count ? count : ans
       }
    }
    return ans
}
~~~





### 무인도 여행

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/154540
- DFS, BFS

~~~swift
import Foundation

func solution(_ maps: [String]) -> [Int] {
    let graph = maps.reduce(into: [[Character]]()) { result, map in
        result.append(Array(map))
    }
    let row = graph.count
    let col = graph[0].count
    let dx = [0, 0, 1, -1]
    let dy = [-1, 1, 0, 0]
    var visit = [[Bool]](repeating: [Bool](repeating: false, count: col), count: row)
    
    func dfs(_ x: Int, _ y: Int) -> Int {
        if graph[x][y] == "X" { return 0 }
        var sum = Int(graph[x][y].asciiValue!) - 48
        visit[x][y] = true
        for i in dx.indices {
            let nx = x + dx[i]
            let ny = y + dy[i]
            if nx >= row || nx < 0 || ny >= col || ny < 0 { continue }
            if visit[nx][ny] { continue }
            visit[nx][ny] = true
            sum += dfs(nx, ny)
        }
        return sum
    }
    
    var ans: [Int] = []
    for i in 0..<row {
        for j in 0..<col {
            if visit[i][j] || graph[i][j] == "X" { continue }
            let sum = dfs(i, j)
            if sum > 0 {
                ans.append(sum)
            }
        }
    }
    return ans.isEmpty ? [-1] : ans.sorted()
}
~~~





### 롤케이크 자르기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/132265
- hash

~~~swift
import Foundation

func solution(_ topping: [Int]) -> Int {
    var dic = topping.reduce(into: [Int: Int]()) { $0[$1, default: 0] += 1 }
    var dic2: [Int: Int] = [:]

    return topping.reduce(into: 0) { ans, type in
        dic2[type, default: 0] += 1
        dic[type, default: 0] -= 1
        dic[type] = dic[type] == 0 ? nil : dic[type]
        ans += dic.count == dic2.count ? 1 : 0
    }
}
~~~





### 뒤에 있는 큰 수 찾기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/154539#
- stack

~~~swift
import Foundation

func solution(_ numbers: [Int]) -> [Int] {
    var dic: [Int: Bool] = [:]
    var stack: [Int] = []
    for (index, number) in numbers.enumerated() {
        if stack.isEmpty { stack.append(number); continue }
        var prevIndex = index - 1
        while prevIndex >= 0 && stack[prevIndex] < number {
            defer { prevIndex -= 1 }
            if dic[prevIndex] != nil { continue }
            stack[prevIndex] = number
            dic[prevIndex] = true
        }
        stack.append(number)
    }
    return stack.enumerated().map { dic[$0.offset] == nil ? -1 : $0.element }
}
~~~





### 숫자 변환하기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/154538
- dynamic programming (as a bottom-up way)

~~~swift
import Foundation

func solution(_ x: Int, _ y: Int, _ n: Int) -> Int {
    var dp: [Int: Int] = [:]
    dp[x] = 0
    for num in x...y {
        if dp[num - n] != nil {
            dp[num] = dp[num-n, default: 0] + 1   
        }
        if num % 2 == 0 && dp[num/2] != nil {
            let prev = dp[num] ?? Int.max
            let now = dp[num/2, default: 0] + 1
            dp[num] = min(prev, now)
        }
        if num % 3 == 0 && dp[num/3] != nil {
            let prev = dp[num] ?? Int.max
            let now = dp[num/3, default: 0] + 1
            dp[num] = min(prev, now)
        }
    }
    return dp[y] == nil ? -1 : dp[y]!
}
~~~





### 전력망을 둘로 나누기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/86971
- brute force, DFS

~~~ swift
import Foundation

var G = [[Int]](repeating: [Int](), count: 101)
var originDic = [Bool](repeating: false, count: 101)
var dic = [Bool](repeating: false, count: 101)
var cutPos = [Int]()
var visitCount = 0

func dfs(at index: Int) {
    for i in G[index].indices {
        let next = G[index][i]
        if dic[next] { continue }
        let route = [index, next]
        if route == cutPos || route == [cutPos[1], cutPos[0]] { continue }
        dic[next] = true
        visitCount += 1
        dfs(at: next)
    }
}

func solution(_ n: Int, _ wires: [[Int]]) -> Int {
    if n == 2 { return 0 }

    for wire in wires {
        G[wire[0]].append(wire[1])
        G[wire[1]].append(wire[0])
    }

    var ans = n-1
    for wire in wires {
        cutPos = wire
        var counts = [Int]()
        dic = originDic
        for i in 1...n {
            if dic[i] { continue }
            dic[i] = true
            visitCount += 1
            dfs(at: i)
            if visitCount > 0 {
                counts.append(visitCount)
                visitCount = 0
            }
            if counts.count == 2 {
                var diff = counts[0] - counts[1]
                diff *= diff < 0 ? -1 : 1
                ans = ans > diff ? diff : ans
                break
            }
        }
    }
    return ans
}
~~~



### 귤 고르기

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/138476
  - sorting, hash

~~~swift
import Foundation

func solution(_ k: Int, _ tangerine: [Int]) -> Int {
    let array = tangerine.reduce(into: [Int: Int]()) { result, num in
        result[num, default: 0] += 1
    }
    .sorted { $0.value > $1.value }
    
    var (count, ans) = (0, 0)
    for tuple in array {
        count += tuple.value
        ans += 1
        if k <= count { break }
    }
    return ans
}
~~~

### 연속 부분 수열 합의 개수

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/131701
  - brute-force, hash

~~~swift
import Foundation

func solution(_ elements: [Int]) -> Int {
    var array = elements + elements
    array.removeLast()
    return (elements.indices).reduce(into: Set<Int>()) { ans, idx in
        var sum = 0
        for jdx in (idx..<idx+elements.count) {
            sum += array[jdx]
            ans.insert(sum)
        }
    }.count
}
~~~



### 피로도

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/87946
  - permutation, brute-force

~~~swift
import Foundation

var permList: [Int] = []
var chk = Set<Int>()
var D: [[Int]] = []
var K = 0
var len = 0
var Ans = 0
func go(_ idx: Int) {
    if len == permList.count {
        var ans = 0
        var k = K
        for idx in permList where D[idx][0] <= k {
            k -= D[idx][1]
            ans += 1
        }
        Ans = Ans < ans ? ans : Ans
        return
    }

    for i in 0..<len {
        if chk.contains(i) { continue }
        chk.insert(i)
        permList.append(i)
        go(idx+1)
        chk.remove(i)
        permList.removeLast()
    }
}

func solution(_ k: Int, _ dungeons:[[Int]]) -> Int {
    len = dungeons.count
    (D, K) = (dungeons, k)
    go(0)
    return Ans
}
~~~



### 혼자 놀기의 달인

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/131130

~~~swift
import Foundation

func solution(_ cards: [Int]) -> Int {
    var dic = [Bool](repeating: false, count: cards.count)
    func checkCount(idx: Int) -> Int {
        var count = 0
        var idx = idx
        while true {
            let newIdx = cards[idx] - 1
            if cards.indices ~= newIdx && dic[newIdx] == false {
                dic[newIdx] = true
                count += 1
                idx = newIdx
                print("number : \(newIdx + 1)")
            } else {
                return count
            }
        }
    }
    
    var (first, second) = (0, 0)
    for idx in cards.indices {
        if dic[idx] { continue }
        let count = checkCount(idx: idx)
        if first < count {
            second = first
            first = count
        } else if second < count {
            second = count
        }
    }

    return first * second
}
~~~



# Level 3

### 연속 펄스 부분 수열의 합

- problem link : https://school.programmers.co.kr/learn/courses/30/lessons/161988
- math

~~~swift
import Foundation

func solution(_ sequence: [Int]) -> Int64 {
    func checkSum(startFlag: Int64) {
        var sum: Int64 = 0
        var flag = startFlag
        for n in sequence.map(Int64.init) {
            let now = n * flag
            if sum + now >= 0 { 
                sum += now 
            } else {
                sum = 0
            }
            ans = ans < sum ? sum : ans
            flag *= -1
        }
    }
    var ans: Int64 = 0
    checkSum(startFlag: 1)
    checkSum(startFlag: -1)
    return ans
}
~~~

