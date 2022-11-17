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

