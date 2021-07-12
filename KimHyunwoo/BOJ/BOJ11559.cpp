#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int ans;
queue<pair<int, int> > Q;
bool flag = true;
char board[12][6], color;
bool visited[12][6];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0; i<12; i++) for(int j=0; j<6; j++) cin >> board[i][j];
	while(flag){
		flag = false;
		for(int i=0; i<12; i++){
			for(int j=0; j<6; j++){
				int cnt = 1;
				if(board[i][j]!='.'){
					color = board[i][j];
					vector<pair<int,int>> visitList;
					Q.push({i,j});
					visitList.push_back({i,j});
					visited[i][j] = true;
					while(!Q.empty()){
						auto cur = Q.front(); Q.pop();
						for(int dir=0; dir<4; dir++){
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if(nx<0 || ny<0 || nx>=12 || ny>=6) continue;
							if(visited[nx][ny]) continue;
							if(board[nx][ny]!=color) continue;
							visited[nx][ny] = true;
							visitList.push_back({nx,ny});
							Q.push({nx,ny});
							cnt++;
						}
					}
					for(int v=0; v<visitList.size(); v++){
						auto cur = visitList[v];
						visited[cur.X][cur.Y] = false;
					}
					if(cnt>3){
						for(int v=0; v<visitList.size(); v++){
							auto cur = visitList[v];
							board[cur.X][cur.Y] = '.';
						}
						if(!flag){
							flag = true;
							ans++;
						}
					}
				}
			}
		}
		for(int i=11; i>=0; i--){
			for(int j=0; j<6; j++){
				if(board[i][j]!='.'){
					int x = i; int y = j;
					while(x!=11 && board[x+1][y]=='.'){
						board[x+1][y] = board[x][y];
						board[x++][y] = '.';
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
