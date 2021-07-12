#include<bits/stdc++.h>
using namespace std;

int N,M;
int arr[10];
void func(int s){
	if(s==M){
		for(int i=0; i<M; i++) cout << arr[i] << "\n";
		return;
	}
	for(int i=0; i<N; i++){
		arr[s] = i+1;
		func(s+1);
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	func(0);
	return 0;
}
