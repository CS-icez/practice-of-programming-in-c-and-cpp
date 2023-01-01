#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int h[111], dp[111];

int main(){
	int K;
	cin >> K;
	
	while (K--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> h[i];
		
		int res = 0;
		for (int i = 1; i <= n; ++i){
			dp[i] = 1;
			for (int j = 1; j < i; ++j)
				if (h[j] < h[i]) dp[i] = max(dp[i], dp[j]+1);
			res = max(res, dp[i]);
		}
		for (int i = 1; i <= n; ++i){
			dp[i] = 1;
			for (int j = 1; j < i; ++j)
				if (h[j] > h[i]) dp[i] = max(dp[i], dp[j]+1);
			res = max(res, dp[i]);
		}
		cout << res << endl;
	}
}
