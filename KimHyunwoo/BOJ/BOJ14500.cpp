#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N,M,ans;
int board[505][505];
vector<vector<pair<int, int>>> tetro = {{{0,1}, {0,2}, {0,3}}, {{1,0}, {2,0}, {3,0}}, {{1,0}, {0,1}, {1,1}}
, {{1,0}, {2,0}, {2,1}}, {{0,1}, {0,2}, {-1,2}}, {{0,1}, {1,1},{2,1}}, {{1,0}, {0,1}, {0,2}}, {{0,1}, {-1,1}, {-2,1}}, {{0,1}, {0,2}, {1,2}}, {{0,1}, {1,0}, {2,0}}, {{1,0}, {1,1}, {1,2}},
{{0,1}, {1,1}, {1,2}}, {{1,0}, {1,-1}, {2,-1}}, {{0,1}, {-1,1}, {-1,2}}, {{1,0}, {1, 1}, {2, 1}}, {{0,-1}, {-1,-1}, {1,-1}}, {{0,1}, {1,1}, {-1,1}}, {{0,1}, {0,2}, {-1,1}}, {{0,1}, {0,2}, {1,1}}};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> board[i][j];
		}
	}
	for(int i=0; i<19; i++){
		for(int x=0; x<N; x++){
			for(int y=0; y<M; y++){
				if(x+tetro[i][0].X>=N || y+tetro[i][0].Y>=M || x+tetro[i][0].X<0 || y+tetro[i][0].Y<0) continue;
				if(x+tetro[i][1].X>=N || y+tetro[i][1].Y>=M || x+tetro[i][1].X<0 || y+tetro[i][1].Y<0) continue;
				if(x+tetro[i][2].X>=N || y+tetro[i][2].Y>=M || x+tetro[i][2].X<0 || y+tetro[i][2].Y<0) continue;
				ans = max(ans, board[x][y]+board[x+tetro[i][0].X][y+tetro[i][0].Y]+board[x+tetro[i][1].X][y+tetro[i][1].Y]+board[x+tetro[i][2].X][y+tetro[i][2].Y]);

			}
		}
	}
	cout << ans;
}
