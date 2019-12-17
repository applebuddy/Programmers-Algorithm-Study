
// MARK: 조이스틱 Lv2

#if 0
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;
    string compStr = "";
    for(int i=0; i<name.length(); i++) compStr += "A";
    int dist=0, nowIdx = 0;
    while(compStr != name) {
            answer += (name[nowIdx] - 'A' > 26 - (name[nowIdx] - 'A')? (26 - (name[nowIdx] - 'A')) : (name[nowIdx] - 'A'));
            compStr[nowIdx] = name[nowIdx];
            int nextIdx = name.length();
            dist = name.length();
            for(int i=0; i<name.length(); i++) {
                if(nextIdx == nowIdx || compStr[i]==name[i]) continue;
                int tDist = min(abs(nowIdx-i),(int)name.length()-abs(nowIdx-i));
                if(dist > tDist) {
                    dist = tDist;
                    nextIdx = i;
                }
            }
            nowIdx = nextIdx;
            if(name == compStr) break;
            answer += dist;
    }
    return answer;
}
#endif
