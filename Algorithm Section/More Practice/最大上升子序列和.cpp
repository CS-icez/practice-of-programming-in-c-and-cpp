#include <iostream>
#include <algorithm>
using namespace std;

int h[1010];
int dp[1010];

int main(){
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; ++i)
		cin >> h[i];
		
	for (int i = 1; i <= n; ++i){
		dp[i] = h[i];
		for (int j = 1; j < i; ++j)
			if (h[j] < h[i]) dp[i] = max(dp[i], dp[j]+h[i]);
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res = max(res, dp[i]);
	cout << res;
		
}
