#include<bits/stdc++.h>
using namespace std;

int T, n, m, pos, ans;
int A[20005];
int B[20005];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for(int tc=0; tc<T; tc++){
		cin >> n >> m;
		ans = 0;
		pos = 0;
		for(int i=0; i<n; i++) cin >> A[i];
		for(int i=0; i<m; i++) cin >> B[i];
		sort(A, A+n);
		sort(B, B+m);
		for(int i=0; i<n; i++){
			ans += pos;
			for(int j=pos; j<m; j++){
				if(A[i]<=B[j]){
					pos = j;
					break;
				}
				else{
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}
