#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define int long long

const int N = 255;
int dp[N][N];	// 从至少j开始拆i的情况数

int f(int beg, int sum){
	if (~dp[beg][sum]) return dp[beg][sum];
	if (beg > sum) return dp[beg][sum] = 0;
	return dp[beg][sum] = dp[beg][sum-beg*2];
}

signed main(){
	for (int i = 0; i < N; ++i)
		dp[0][i] = 1;
	
	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j){
			if (j > i) continue;
			dp[i][j] = 1;
			for (int k = j; k*2 <= i; ++k)	// 枚举第一个数
				dp[i][j] += dp[i-2*k][k];
		}
	
	int n;
	while (cin >> n, n){
		cout << n << " " << dp[n][1] << endl;
	}
}
