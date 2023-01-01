#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110, M = 13;
int dp[N][M];

int main(){
	int n, m;
	
	for (int i = 1; i < N; ++i)
		dp[i][1] = i;
	for (int j = 1; j < M; ++j)
		dp[1][j] = 1;
		
	for (int i = 2; i < N; ++i)
		for (int j = 2; j < M; ++j){
			dp[i][j] = 1e9;
			for (int k = 1; k <= i; ++k)
				dp[i][j] = min(dp[i][j], max(dp[k-1][j-1], dp[i-k][j])+1);
		}
	
	while (cin >> n >> m)
		cout << dp[n][m] << endl;
}
