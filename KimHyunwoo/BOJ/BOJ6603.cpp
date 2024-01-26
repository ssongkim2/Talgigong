#include<bits/stdc++.h>
using namespace std;

vector<pair<bool, int>> arr;
int cur[10];
int n;
void func(int s, int idx){
  if(s==6){
	for(int i=0; i<6; i++) cout << cur[i] << " ";
	cout << "\n";
	return;
  }
  for(int i=0; i<n; i++){
  	if(i<idx) continue;
  	if(arr[i].first==false){
  		arr[i].first = true;
  		cur[s] = arr[i].second;
  		func(s+1, i);
  		arr[i].first = false;
	  }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc=0;
  cin >> n;
  while(n!=0){
  	arr.clear();
    for(int i=0; i<n; i++){
      int temp;
      cin >> temp;
      arr.push_back({0, temp});
    }
    func(0,0);
    cout << "\n";
    cin >> n;
    tc++;
  }
  return 0;
}

