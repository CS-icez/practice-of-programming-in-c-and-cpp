#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 222, X = 10010;
int n, x;
int a[X];
int dp[X], without[X];	//dp[j]存用所有物品达到j的情况数，without([i])[j]存不用i达到j的情况数
int cnt, ans[X];

signed main(){
	cin >> n >> x;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
		
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = x; j >= a[i]; --j)
			dp[j] += dp[j-a[i]];
			
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j <= x; ++j)
			without[j] = j<a[i]? dp[j]: dp[j]-without[j-a[i]];
			
		if (!without[x]) ans[cnt++] = a[i];
	}
	
	sort(ans, ans+cnt);
	cout << cnt << endl;
	for (int i = 0; i < cnt; ++i){
		if (i) cout << " ";
		cout << ans[i];
	}
}
