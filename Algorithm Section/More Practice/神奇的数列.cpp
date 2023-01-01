#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

const int N = 211;
int a[N];
int dp[N][N];

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t){	
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
			
		memset(dp, 0x3f, sizeof dp);
		for (int i = 1; i <= n; ++i)
			dp[i][i] = 1;
		for (int i = 1; i < n; ++i)
			dp[i][i+1] = 1+(a[i]!=a[i+1]);
			
		for (int i = n-2; i; --i)
			for (int j = i+2; j <= n; ++j)
				if (a[i] == a[j])
					dp[i][j] = dp[i][j-1];
				else
					for (int k = i; k < j; ++k)
						dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
			
				
		printf("Case %d: %d\n", t, dp[1][n]);
	}
}
