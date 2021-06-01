#include<bits/stdc++.h>
using namespace std;
bool curMST[10001];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int V,E,ans=0;
	cin >> V >> E;
	vector<vector<pair<int,int>>> adj_list(V+1, vector<pair<int,int>>());
	priority_queue<pair<int,int>> pq;
	for(int i=0; i<E; i++){
		int a,b,c;
		cin >> a >> b >> c;
		adj_list[a].push_back({c,b});
		adj_list[b].push_back({c,a});
	}
	curMST[1] = true;
	for(auto n : adj_list[1]){
		pq.push({-n.first, n.second});
	}
	while(!pq.empty()){
		auto node = pq.top(); pq.pop();
		if(curMST[node.second]==true) continue;
		ans += -node.first;
		curMST[node.second] = true;
		for(auto n : adj_list[node.second]){
			if(curMST[n.second]==true) continue;
			pq.push({-n.first, n.second});
		}
	}
	cout << ans;
}
