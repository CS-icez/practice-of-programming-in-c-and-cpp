#include <iostream>
using namespace std;

int dp[33], sum[33];

int main(){
	dp[0] = 1, sum[0] = 1;
	dp[1] = 0, sum[1] = 1;
	for (int i = 2; i <= 30; i += 2){
		dp[i] = dp[i-2]+2*sum[i-2];
		sum[i] = sum[i-2] + dp[i];
	}
	
	int n;
	while (cin >> n, ~n){
		if (n&1) cout << 0 << endl;
		else cout << dp[n] << endl;
	}
}
