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

const int N = 1011;
int n;
int a[N];
int dp[N];

int main(){
	int T;
	cin >> T;
	
	while (T--){
		memset(dp, 0, sizeof dp);
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		
		for (int i = 1; i <= n; ++i)
			for (int j = i; ~j; --j){
				dp[j] += a[i]==i-j;
				if (j) dp[j] = max(dp[j], dp[j-1]+(a[i+1]==i-j));
			}
			
		int res = 0;
		for (int j = 0; j <= n; ++j)
			res = max(res, dp[j]);
		cout << res << endl;
	}
}
