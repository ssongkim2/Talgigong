#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int trucks[1005];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w, L, ans=0, current_sum = 0;
    deque<pair<int,int>> v;
    cin >> n >> w >> L;
    for(int i=0; i<n; i++) cin >> trucks[i];
    for(int i=0; i<n; i++){
    	ans++;
    	for(int j=0; j<v.size(); j++) v[j].second++;
        if(v.front().s>w){
            current_sum -= v.front().f;
            v.pop_front();
		}
        while(current_sum+trucks[i]>L){
            ans++;
            for(int j=0; j<v.size(); j++) v[j].s++;
            if(v.front().s>w){
            	current_sum -= v.front().f;
            	v.pop_front();
			}
        }
        current_sum += trucks[i];
        v.push_back({trucks[i],1});
    }
    while(v.size()!=0){
        ans++;
        for(int j=0; j<v.size(); j++) v[j].second++;
        if(v.front().s>w){
            current_sum -= v.front().f;
            v.pop_front();
		}
    }
    cout << ans;
}
