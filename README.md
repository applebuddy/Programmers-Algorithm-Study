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

