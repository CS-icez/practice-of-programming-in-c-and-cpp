#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1011, M = 23911;
int a[N];
int dp[N][M];
int pre[N][M];
int ans[N], cnt;

signed main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	//前i件，至少j元，至少多少钱
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= m; ++j){
			dp[i][j] = dp[i-1][j];
			if (a[i] <= j) dp[i][j] = min(dp[i][j], dp[i-1][j-a[i]]+a[i]);
			else dp[i][j] = min(dp[i][j], a[i]);
		}
		
	int w = dp[n][m];	//最少的钱
	cout << w << " ";
	
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	//前i件，j元，多少种方案
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= w; ++j){
			dp[i][j] = dp[i-1][j];
			if (j >= a[i]) dp[i][j] += dp[i-1][j-a[i]];
			//printf("i=%d j=%d dp=%d\n", i, j, dp[i][j]);
		}
		
	cout << dp[n][w] << endl;
	
	if (dp[n][w] != 1) return 0;
	
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	//前i件，j元，多少种方案
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= w; ++j){
			dp[i][j] = dp[i-1][j];
			if (dp[i][j]){
				pre[i][j] = 0;
				continue;
			}
			if (j >= a[i]) dp[i][j] += dp[i-1][j-a[i]];
			if (dp[i][j]) pre[i][j] = 1;
			//printf("i=%d j=%d dp=%d\n", i, j, dp[i][j]);
		}
	
	int i = n, j = w;
	while (i){
		if (pre[i][j]){
			ans[cnt++] = i;
			j -= a[i];
			--i;
		}
		else{
			--i;
		}
	}
	int f = 0;
	for (int k = cnt-1; k >= 0; --k){
		if (f) cout << " ";
		f = 1;
		cout << ans[k];
	}
		
}
