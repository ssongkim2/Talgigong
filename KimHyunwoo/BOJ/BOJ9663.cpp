#include<bits/stdc++.h>
using namespace std;

int board[70][70];
int n;
int ans = 0;

void queen(int cur){
	if(cur==n-1){
		for(int i=0; i<n; i++){
			if(board[cur][i]==0) ans++;
		}
		return;
	}
	for(int i=0; i<n; i++){
		if(board[cur][i]>0) continue;
		board[cur][i]++;
		for(int j=cur+1; j<n; j++){
			board[j][i]++;
			if(i-(j-cur)>=0) board[j][i-(j-cur)]++;
			if(i+(j-cur)<n) board[j][i+(j-cur)]++;
		}
		queen(cur+1);
		board[cur][i]--;
		for(int j=cur+1; j<n; j++){
			board[j][i]--;
			if(i-(j-cur)>=0) board[j][i-(j-cur)]--;
			if(i+(j-cur)<n) board[j][i+(j-cur)]--;
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	queen(0);
	cout << ans;
}
