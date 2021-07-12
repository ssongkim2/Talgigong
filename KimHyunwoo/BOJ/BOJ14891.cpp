#include<bits/stdc++.h>
#define POS first
#define DIR second
using namespace std;

vector<deque<char>> gears(5);
pair<int, int> CMD[105];
int K;

void move(int pos, int dir){
	if(dir==1){
		char temp = gears[pos].back(); 
		gears[pos].pop_back();
		gears[pos].push_front(temp);
	}
	else{
		char temp = gears[pos].front(); 
		gears[pos].pop_front();
		gears[pos].push_back(temp);
	}
}

void change(int gear, int nxt, int dir){
	if(gear<=1 && nxt == -1){
		move(gear, dir);
		return;
	} 
	if(gear>=4 && nxt == 1){
		move(gear, dir);
		return;
	}
	if(nxt==2){
		change(gear, -1, dir);
		move(gear, -dir);
		change(gear, 1, dir);
	}
	else if(nxt==-1){
		if(gears[gear][6]!=gears[gear-1][2]) change(gear-1, -1, -dir);
		move(gear, dir);
	}
	else{
		if(gears[gear][2]!=gears[gear+1][6]) change(gear+1, 1, -dir);
		move(gear, dir);
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1; i<=4; i++){
		for(int j=0; j<8; j++){
			char val;
			cin >> val;
			gears[i].push_back(val);
		}
	}
	cin >> K;
	for(int i=0; i<K; i++){
		int pos, dir;
		cin >> pos >> dir;
		CMD[i] = {pos, dir};
	}
	for(int i=0; i<K; i++){
		auto cur = CMD[i];
		if(cur.POS==1) change(cur.POS, 1, cur.DIR);
		else if(cur.POS==4) change(cur.POS, -1, cur.DIR);
		else change(cur.POS, 2, cur.DIR);
	}
	cout << (gears[1].front()-'0') + (gears[2].front()-'0')*2 + (gears[3].front()-'0')*4 + (gears[4].front()-'0')*8;
	return 0;
}
