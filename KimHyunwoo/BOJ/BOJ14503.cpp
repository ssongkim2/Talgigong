#include<bits/stdc++.h>
#define CLEAN 1
using namespace std;

bool graph[51][51];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,r,c,d,cnt=0;
	cin >> n >> m >> r >> c >> d;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> graph[i][j];
		}
	}
	while(true){
		if(graph[r][c]==0){
			cnt++;
			graph[r][c] = CLEAN;
		}
		else{
			if(){
				sdsd
			}
			else if(){
				asdasd;
			}
			else if(){
				asdasd;
			}
			else break;
		}
	}
}
