#include <iostream>
using namespace std;

int a[24];
int dp[24][1020];

int main(){
	int n, t;
	cin >> n >> t;
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
		
	for (int i = 0; i <= n; ++i)
		dp[i][0] = 1;
		
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= t; ++j){
			dp[i][j] = dp[i-1][j];
			if (j >= a[i]) dp[i][j] += dp[i-1][j-a[i]];
		}
		
	cout << dp[n][t];
			
}
