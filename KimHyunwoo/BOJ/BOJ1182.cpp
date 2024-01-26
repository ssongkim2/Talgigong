#include<bits/stdc++.h>
using namespace std;

int N, S, ans, arr[21];
bool used[21];

void func(int cur, int idx){
	cur += arr[idx];
	if(cur==S){
		ans++;
	}
	if(idx==N-1){
		return;
	}
	for(int i=idx+1; i<N; i++){
		func(cur, i);
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	for(int i=0; i<N; i++) cin >> arr[i];
	for(int i=0; i<N; i++) func(0, i);
	cout << ans;
}
