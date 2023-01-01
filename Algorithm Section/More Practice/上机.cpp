#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int N = 10011, INF = 0X3F3F3F3F;
int a[N], b[N], c[N];
int dp[N][2][2];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	for (int i = 1; i <= n; ++i)
		cin >> c[i];		
		
	dp[1][1][0] = dp[1][1][1] = -INF;
	dp[1][0][0] = a[1];
	dp[1][0][1] = b[1];
		
	for (int i = 2; i <= n+1; ++i){
		dp[i][0][0] = max(dp[i-1][0][1], dp[i-1][1][1])+a[i];
		dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][1])+b[i];
		dp[i][1][0] = max(dp[i-1][0][0], dp[i-1][1][0])+b[i];
		dp[i][1][1] = max(dp[i-1][0][0], dp[i-1][1][0])+c[i];
	}
	
	cout << dp[n+1][1][0];
}
