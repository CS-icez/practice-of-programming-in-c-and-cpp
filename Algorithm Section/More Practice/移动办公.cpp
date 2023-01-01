#include <bits/stdc++.h>
using namespace std;

const int T = 111;
int p[T], n[T];
int dp[T][2];

int main(){
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= t; ++i)
		cin >> p[i] >> n[i];
		
	for (int i = 1; i <= t; ++i){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]-m)+p[i];
		dp[i][1] = max(dp[i-1][1], dp[i-1][0]-m)+n[i];
	}
	
	cout << max(dp[t][0], dp[t][1]);
}
