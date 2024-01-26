#include <bits/stdc++.h>
using namespace std;

int L, R, C, sx, sy, sz, ans;
char board[35][35][35];
int dist[35][35][35];
int dx[] = {-1,0,0,1,0,0};
int dy[] = {0,-1,0,0,1,0};
int dz[] = {0,0,-1,0,0,1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> R >> C;
    while(L!=0 && R!=0 && C!=0){
    	bool flag = false;
    	int ex = 0, ey = 0, ez = 0;
      for(int i=0; i<L; i++)
        for(int j=0; j<R; j++)
          for(int k=0; k<C; k++){
            cin >> board[i][j][k];
            dist[i][j][k] = 0;
            if(board[i][j][k]=='S'){
              sx = i;
              sy = j;
              sz = k;
            }
          }
      queue<tuple<int, int, int>> Q;
      Q.push(make_tuple(sx, sy, sz));
      while(!Q.empty() && !flag){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<6; dir++){
          int nx = get<0>(cur) + dx[dir];
          int ny = get<1>(cur) + dy[dir];
          int nz = get<2>(cur) + dz[dir];
          if(nx<0 || ny<0 || nz<0 || nx>=L || ny>=R || nz>=C) continue;
          if(board[nx][ny][nz]=='#') continue;
          dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
          if(board[nx][ny][nz]=='E'){
          	flag = true;
          	ex = nx; ey = ny; ez= nz;
          	break;
		  }
          board[nx][ny][nz] = '#';
          Q.push(make_tuple(nx,ny,nz));
        }
      }
      if(flag) cout << "Escaped in " << dist[ex][ey][ez] << " minute(s).\n";
      else cout << "Trapped!\n";
      cin >> L >> R >> C;
    }
}
