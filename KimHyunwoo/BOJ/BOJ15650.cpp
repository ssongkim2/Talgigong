#include<bits/stdc++.h>
using namespace std;

int arr[8] = {1,2,3,4,5,6,7,8};
bool isUsed[8];
int ans[8];
int N,M;

void func(int s, int idx){
	if(s==M){
		for(int i=0; i<M; i++) cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for(int i=0; i<N; i++){
		if(isUsed[i] == true) continue;
		if(i<idx) continue;
		isUsed[i] = true;
		ans[s] = arr[i];
		func(s+1, i);
		isUsed[i] = false;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	func(0,0);
}
