#include<bits/stdc++.h>
#define CLEAN 1
#define NC 0
using namespace std;

int n, m, r, c, d, cnt, step, searchCnt;
int dir[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
bool graph[51][51];
bool cleaned[51][51];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> r >> c >> d;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> graph[i][j];
		}
	}
	while(true){
		if(step==0){
			cnt++;
			cleaned[r][c] = CLEAN;
			step = 1;
		}
		else if(step==1){
			d = (d+3)%4;
			searchCnt++;
			if(r+dir[0][d]<0 || c+dir[1][d]<0 || r+dir[0][d]>=n || c+dir[1][d]>=m){
				if(searchCnt==4){
					searchCnt = 0;
					step = 2;
				}
			}
			else if(graph[r+dir[0][d]][c+dir[1][d]]==0 && cleaned[r+dir[0][d]][c+dir[1][d]]==0){
				r = r + dir[0][d];
				c = c + dir[1][d];
				step = 0;
				searchCnt = 0;
			}
			else{
				if(searchCnt==4){
					searchCnt = 0;
					step = 2;
				}
			}
		}
		else if(step==2){
			if(r-dir[0][d]<0 || c-dir[1][d]<0 || r-dir[0][d]>=n || c-dir[1][d]>=m) break;
			if(graph[r-dir[0][d]][c-dir[1][d]]==1) break;
			r = r - dir[0][d];
			c = c - dir[1][d];
			step = 1;
		}
	}
	cout << cnt;
}
