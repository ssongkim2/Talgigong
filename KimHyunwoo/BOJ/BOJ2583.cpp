#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[100][100];
int ans;
vector<int> siz;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,num;
	queue<pair<int,int>> Q;
	cin >> m >> n >> num;
	for(int i=0; i<num; i++){
		int lx,ly,rx,ry;
		cin >> lx >> ly >> rx >> ry;
		for(int w=m-ry; w<m-ly; w++){
			for(int h=lx; h<rx; h++)
				board[w][h] = 1;
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			int area;
			if(board[i][j]==0){
				area = 1;
				Q.push({i,j}); ans++;
				board[i][j] = 1;
				while(!Q.empty()){
					auto cur = Q.front(); Q.pop();
					for(int dir=0; dir<4; dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx<0||nx>=m||ny<0||ny>=n) continue;
						if(board[nx][ny]==1) continue;
						Q.push({nx,ny}); board[nx][ny] = 1; area++;
					}
				}
				if(area>0) siz.push_back(area);
			}
		}
	}
	sort(siz.begin(),siz.end());
	cout << ans << "\n";
	for(int i=0; i<siz.size(); i++) cout << siz[i] << " ";
	return 0;
}
