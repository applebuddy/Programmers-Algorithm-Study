
#if 0
#include <vector>
#include <string.h>
#include <stdio.h>
#include <queue>
#define MAX 101

using namespace std;

int tx[] = {0,0,1,-1};
int ty[] = {1,-1,0,0};
int chk[MAX][MAX];
int M,N,maxCount=0;
void BFS(int x, int y, vector<vector<int>> &p){
    int c = p[x][y];
    int count = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    chk[x][y]=c;
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int mx = nx+tx[i];
            int my = ny+ty[i];
            if(mx>=0 && mx<M && my>=0 && my<N){
                if(chk[mx][my]==0 && p[mx][my]==c){
                    chk[mx][my]=c;
                    count++;
                    q.push(make_pair(mx,my));
                }
            }
        }
    }
    maxCount = max(maxCount,count);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for(int i=0; i<MAX; i++){
        memset(chk[i],0,sizeof(MAX));
    }
    
    N=n;
    M=m;
    vector<int> answer(2);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(chk[i][j]==0 && picture[i][j]!=0){
                BFS(i,j,picture);
                number_of_area++;
            }
        }
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d",chk[i][j]);
        }
        printf("\n");
    }
    
    answer[0] = number_of_area;
    answer[1] = maxCount;
    return answer;
}
#endif
