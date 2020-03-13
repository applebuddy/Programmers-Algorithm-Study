
// MARK: 카드게임 42896
// MARK: DP C++ 문제풀이

#if 0
#include <string>
#include <vector>
using namespace std;

int DP[2001][2001];
int go(int lc, int rc, const vector<int> &L, const vector<int> &R) {
    if(lc == (int)L.size() || rc == (int)R.size()) return 0;
    if(DP[lc][rc]>0) return DP[lc][rc];
    DP[lc][rc] = max(go(lc+1,rc+1,L,R), go(lc+1,rc,L,R));
    if(L[lc] > R[rc]) {
        DP[lc][rc] = max(DP[lc][rc], R[rc]+go(lc,rc+1,L,R));
    }
    return DP[lc][rc];
}

int solution(vector<int> left, vector<int> right) {
    return go(0,0,left,right);
}
#endif
