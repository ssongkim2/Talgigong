#include<bits/stdc++.h>
using namespace std;

int N, M, x, y, K, s, h;
int dir;
int cmd[1005];
int board[20][20];
vector<int> nums(6);

void move(int c){
	vector<int> tmp = nums;
	if(c==1){
		if(y+1>=M) return;
		y++;
		nums[0] = tmp[4];
        nums[1] = tmp[5];
        nums[4] = tmp[1];
        nums[5] = tmp[0];
		if(board[x][y]){
			nums[1] = board[x][y];
			board[x][y] = 0;
		}
		else{
			board[x][y] = nums[1];
		}
		cout << nums[0] << "\n";
	}
	else if(c==2){
		if(y-1<0) return;
		y--;
		nums[0] = tmp[5];
        nums[1] = tmp[4];
        nums[4] = tmp[0];
        nums[5] = tmp[1];
		if(board[x][y]){
			nums[1] = board[x][y];
			board[x][y] = 0;
		}
		else{
			board[x][y] = nums[1];
		}
		cout << nums[0] << "\n";
	}
	else if(c==3){
		if(x-1<0) return;
		x--;
		nums[0] = tmp[3];
        nums[1] = tmp[2];
        nums[2] = tmp[0];
        nums[3] = tmp[1];
		if(board[x][y]){
			nums[1] = board[x][y];
			board[x][y] = 0;
		}
		else{
			board[x][y] = nums[1];
		}
		cout << nums[0] << "\n";
	}
	else if(c==4){
		if(x+1>=N) return;
		x++;
		nums[0] = tmp[2];
        nums[1] = tmp[3];
        nums[2] = tmp[1];
        nums[3] = tmp[0];
		if(board[x][y]){
			nums[1] = board[x][y];
			board[x][y] = 0;
		}
		else{
			board[x][y] = nums[1];
		}
		cout << nums[0] << "\n";
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> x >> y >> K;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++) cin >> board[i][j];
	}
	for(int i=0; i<K; i++) cin >> cmd[i];
	for(int i=0; i<K; i++) move(cmd[i]);
}
