#include <bits/stdc++.h>
using namespace std;

const int N = 1011, K = 13, M = 1011;
int a[N], b[N], c[N];
int dp[2][M][K];	//at start of n-th turns, with m hp left, use k cards

int main(){
	int n, f, m, h;
	cin >> n >> f >> m >> h;
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i] >> c[i];
	
	memset(dp, -1, sizeof dp);
	dp[1][m][0] = 0;
		
	for (int i = 1; i <= n; ++i){
		int cur = i&1, nxt = cur^1;
		memset(dp[nxt], -1, sizeof dp[nxt]);
		for (int j = 1; j <= m; ++j){
			for (int k = 0; k <= f; ++k){
				int& t = dp[cur][j][k];
				
				if (t == -1) continue;
				
				if (t+b[i] >= h){
					cout << i;
					return 0;
				}
				
				
				if (j >= a[i])
					dp[nxt][j-a[i]][k] = max(dp[nxt][j-a[i]][k], t+b[i]);
				
				int hp = min(m, j+c[i])-a[i];
				if (hp > 0)
					dp[nxt][hp][k] = max(dp[nxt][hp][k], t);
				
				if (k <= f) 
					dp[nxt][j][k+1] = max(dp[nxt][j][k+1], t);
			}
		}

	}

	
	cout << "Fail";
}
