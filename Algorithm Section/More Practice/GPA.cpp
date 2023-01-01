#include <bits/stdc++.h>
using namespace std;

const int N = 4044, INF = 0X3F3F3F3F;
int x[N], y[N];
int dp[N][N];	//pre i course, sad j, min total score

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];
	
	memset(dp, 0x3f, sizeof dp);
	dp[1][0] = min(x[1], y[1]);
		
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < i; ++j){
			if (dp[i][j] == INF) continue;
			int pre = dp[i][j];
			
			int t = pre > i*x[i+1];
			dp[i+1][j+t] = min(dp[i+1][j+t], pre+x[i+1]);

			t = pre > i*y[i+1];
			dp[i+1][j+t] = min(dp[i+1][j+t], pre+y[i+1]);			
		}
		
	for (int j = 0; j <= n; ++j)
		if (dp[n][j] != INF){
			cout << j;
			return 0;
		}
}
