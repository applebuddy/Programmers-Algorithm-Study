

// MARK: 탑 Lv2 문제풀이
#if 0
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size());
    for(int i=0; i<heights.size(); i++) {
        for(int j=i-1; j>=0; j--) {
            if(heights[j]>heights[i]) {
                answer[i] = j+1;
                break;
            }
        }
    }
    return answer;
}
#endif
