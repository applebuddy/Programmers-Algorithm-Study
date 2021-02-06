
// MARK: - 신규아이디추천 72410 Kakao Lv2

/*
extension Character {
    var isValid: Bool {
        let asciiVal = asciiValue!
        if asciiVal >= 97 && asciiVal <= 122
            || asciiVal >= 48 && asciiVal <= 57
            || self == "-" || self == "_" || self == "." { return true }
        return false
    }
}

extension String {
    mutating func removeRepeatingDot() {
        var newString: String = ""
        var isPrevDot: Bool = false
        forEach { char in
            if isPrevDot, char == "." { return }
            else { newString += "\(char)" }
            isPrevDot = char == "." ? true : false
        }
        self = newString
    }
}

func solution(_ new_id: String) -> String {
    var idString = new_id.lowercased().filter { $0.isValid }
    idString.removeRepeatingDot()

    while !idString.isEmpty, idString.first! == "." {
        idString.removeFirst()
    }

    while !idString.isEmpty, idString.last! == "." {
        idString.removeLast()
    }

    if idString.isEmpty {
        idString = "a"
    }

    if idString.count >= 16 {
        idString = String(idString.prefix(15))
        while idString.last! == "." {
            idString.removeLast()
        }
    }

    if idString.count <= 2 {
        let lastChar = idString.last!
        while idString.count < 3 {
            idString.append(lastChar)
        }
    }

    return idString
}
*/
