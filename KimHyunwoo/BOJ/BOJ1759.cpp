#include<bits/stdc++.h>
using namespace std;

int L, C;
char temp;
char ans[15];
bool isUsed[15];
vector<char> arr;

void func(int s, int idx, int x, int y){
	if(s==L){
		if(x>0 && y>1){
			for(int i=0; i<L; i++) cout << ans[i];
			cout << "\n";
		}
		return;
	}
	for(int i=idx; i<C; i++){
		ans[s] = arr[i];
		if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') func(s+1, i+1, x+1, y);
		else func(s+1, i+1, x, y+1);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> L >> C;
	for(int i=0; i<C; i++){
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	func(0, 0, 0, 0);
	return 0;
}
