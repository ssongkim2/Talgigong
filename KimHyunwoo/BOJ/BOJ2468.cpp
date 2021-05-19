#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int board[105][105];
bool visited[105][105];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans=0;
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) cin >> board[i][j];	

	for(int rain=0; rain<100; rain++){
		int cnt = 0;
		queue<pair<int,int>> Q;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) visited[i][j] = false;
			
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(board[i][j]>rain && visited[i][j] == false){
					cnt++;
					Q.push({i,j});
					visited[i][j] = true;
					while(!Q.empty()){
						auto cur = Q.front(); Q.pop();
						for(int dir=0; dir<4; dir++){
							int nx = cur.X+dx[dir]; int ny = cur.Y+dy[dir];
							if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
							if(board[nx][ny]<=rain) continue;
							if(visited[nx][ny]==true) continue;
							Q.push({nx,ny});
							visited[nx][ny] = true;
						}
					}
				}
			}
		}
		ans = max(ans,cnt);
	}
	cout << ans;
}
