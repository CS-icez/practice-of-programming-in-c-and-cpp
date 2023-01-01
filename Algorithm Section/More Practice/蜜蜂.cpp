#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <queue>
using namespace std;

#define int long long
int dp[55];

signed main(){
	dp[1] = 1, dp[2] = 1;
	for (int i = 3; i <= 50; ++i)
		dp[i] = dp[i-1]+dp[i-2];
		
	int n, a, b;
	cin >> n;
	while (n--){
		cin >> a >> b;
		cout << dp[b-a+1] << endl;
	}
}
