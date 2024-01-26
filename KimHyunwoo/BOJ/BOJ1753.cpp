#include<bits/stdc++.h>
#define INF 987654321
#define f first
#define s seconde
using namespace std;

int graph[20005];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int V, E, K;
	vector<pair<int,int>> edges(n+1);
	priority_queue<pair<int,int>> pq;
	cin >> V >> E >> K;
	for(int i=0; i<E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({w,v});
		graph[i+1] = INF;
	}
	graph[K] = 0;
	for(int i=0; i<edges[K].size(); i++) pq.push({-edges[K][i].f, edges[K][i].s})
	while(!pq.empty()){
		auto cur = pq.top();
		if(graph[pq.s])
	}
}
