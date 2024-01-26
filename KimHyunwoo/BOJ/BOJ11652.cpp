#include<bits/stdc++.h>
using namespace std;

long long N, ans;
long long arr[2^64];
vector<long long> val;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i=0; i<N; i++){
		int temp;
		cin >> temp;
		val.push_back(temp);
		arr[temp]++;
	}
	for(int i=0; i<val.size(); i++){
		ans = max(ans, arr[val[i]]);
	}
	cout << ans;
}
