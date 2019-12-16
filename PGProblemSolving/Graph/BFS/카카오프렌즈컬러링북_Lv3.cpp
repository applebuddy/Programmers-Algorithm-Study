//
//  카카오프렌즈컬러링북_Lv3.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 20/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 카카오프렌즈 컬러링뷱 : 카카오 BFS 문제
#if 0
#include <vector>
#include <string.h>
#include <stdio.h>
#include <queue>

using namespace std;

int tx[] = {0,0,1,-1};
int ty[] = {1,-1,0,0};
int chk[101][101];
int N,M,maxCount;

int maxVf(const int &a, const int &b) {
    if(a>b) return a;
    else return b;
}

void BFS(int x, int y, vector<vector<int>> &p) {
    int c = p[x][y];
    int count = 1;
    
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    chk[x][y]=c;
    while(!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int mx = nx+tx[i];
            int my = ny+ty[i];
            if(mx>=0 && mx<M && my>=0 && my<N) {
                if(chk[mx][my]==0 && p[mx][my]==c) {
                    chk[mx][my]=c;
                    count++;
                    q.push(make_pair(mx,my));
                }
            }
        }
    }
    maxCount = maxVf(maxCount,count);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    M=0, N=0;
    maxCount = 0;
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for(int i=0; i<m+1; i++) {
        memset(chk[i], 0, sizeof(chk[i]));
    }
    N=n;
    M=m;
    vector<int> answer(2,0);
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(chk[i][j]==0 && picture[i][j]!=0) {
                BFS(i,j,picture);
                number_of_area++;
            }
        }
    }
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("%d", chk[i][j]);
        }
        printf("\n");
    }
    
    max_size_of_one_area = maxCount;
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
#endif
