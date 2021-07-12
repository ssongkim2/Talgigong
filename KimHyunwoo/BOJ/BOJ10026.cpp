#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char map[105][105];
bool visited[105][105];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j]!=false){
				
			}
		}
	}
}
