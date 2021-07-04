
import Foundation

func factorCount(of num: Int) -> Int {
    if num == 1 { return 1 }
    return (1...num/2).reduce(into: 1) { (count, value) in
        count += num % value == 0 ? 1 : 0
    }
}

func solution(_ left:Int, _ right:Int) -> Int {
    return (left...right).reduce(into: 0) { (result, target) in
        let count = factorCount(of: target)
        result += count % 2 == 0 ? target : -target
    }
}
