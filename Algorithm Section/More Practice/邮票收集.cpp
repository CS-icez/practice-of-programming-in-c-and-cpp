#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

const int N = 111, K = 1011, INF = 0X3F3F3F3F;
int a[N];
int dp[K];

int main(){
	int n, k;
	
	while (cin >> n >> k, n){
		memset(dp, 0x3F, sizeof dp);
		dp[0] = 0;	//note here
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
			for (int j = a[i]; j <= k; ++j)
				dp[j] = min(dp[j], dp[j-a[i]]+1);
				
		cout << (dp[k]==INF? -1: dp[k]) << endl;
	}
	
	
	
}
