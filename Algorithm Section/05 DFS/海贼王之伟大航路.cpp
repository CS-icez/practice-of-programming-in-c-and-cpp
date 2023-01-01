#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 17;
int n;
int cost[N][N];
int dp[1<<N][N];

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> cost[i][j];
	
	memset(dp, 0x3f, sizeof dp);
	dp[1][0] = 0;
			
	for (int i = 1; i < (1<<n); ++i)
		for (int j = 0; j < n; ++j){
			if (!(i&1<<j)) continue;
			if (dp[i][j] > 1e8) continue;
			for (int k = 0; k < n; ++k)
				if (!(i&1<<k))
					dp[i^1<<k][k] = min(dp[i^1<<k][k], dp[i][j]+cost[j][k]);
		}
		
	cout << dp[(1<<n)-1][n-1] << endl;
}
