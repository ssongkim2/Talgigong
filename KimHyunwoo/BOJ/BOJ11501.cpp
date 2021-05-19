#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
    int test_case;
    cin >> test_case;
    for(int tc=0; tc<test_case; tc++){
        int n, mx = 0;
        long long ans = 0;
        int arr[1000005];
        cin >> n;
        for(int i=1; i<=n; i++) cin >> arr[i];
        for(int i=n; i>0; i--){
            if(mx>arr[i]) ans += mx - arr[i];
            else mx = max(arr[i], mx);
        }
        cout << ans << "\n";
    }
}
