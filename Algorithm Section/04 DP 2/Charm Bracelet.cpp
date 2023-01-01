#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 3410, M = 12900;
int n, m;
int w[N], v[N];
int dp[M];

signed main(){
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> w[i] >> v[i];
		
	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= w[i]; --j)
			dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
		
	cout << dp[m];
}
