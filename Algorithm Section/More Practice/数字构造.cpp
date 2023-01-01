#include <bits/stdc++.h>
using namespace std;

const int N = 23;
int n;
int a[N][3];
long long dp[N][3];

int main(){
	cin >> n;
	for (int i = 1, p, q; i <= n; ++i){
		cin >> p;
		while (p--) cin >> q, ++a[i][q%3];
	}
	
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
				dp[i][j] += dp[i-1][k]*a[i][(j-k+3)%3];
	
	cout << dp[n][0];
}
