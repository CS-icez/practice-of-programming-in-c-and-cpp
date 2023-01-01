#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100011;
int price[N];
int dp1[N], dp2[N];
//dp1[i]表示在[1, i]进行一次股票买卖的最大收益
//dp2[i]表示在[i, n]进行一次股票买卖的最大收益

int main(){
	int T;
	cin >> T;
	while (T--){
		memset(dp2, 0, sizeof dp2);
		
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			scanf("%d", price+i);
		
		for (int i = 2, t = price[1]; i <= n; ++i){
			t = min(t, price[i]);
			dp1[i] = max(dp1[i-1], price[i]-t);	//以第i天是否卖了股票划分
		}
		
		for (int i = n-1, t = price[n]; i; --i){
			t = max(t, price[i]);
			dp2[i] = max(dp2[i+1], t-price[i]);	//以第i天是否买了股票划分
		}
		
		int res = 0;
		for (int i = 1; i <= n; ++i)
			res = max(res, dp1[i]+dp2[i]);
		cout << res << endl;
	}
}
