#include <bits/stdc++.h>
using namespace std;

const int N = 111;
int m[N], p[N], dp[N];

int main(){
	int T;
	cin >> T;
	
	while (T--){
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
			cin >> m[i];
		for (int i = 1; i <= n; ++i)
			cin >> p[i];
			
		dp[1] = p[1];
		int pre = 0, idx = 0;
		for (int i = 2; i <= n; ++i){
			while (m[i]-m[idx+1] > k){
				++idx;
				pre = max(pre, dp[idx]);
			} 
			
			dp[i] = pre+p[i];
		}
		
		while (idx < n) pre = max(pre, dp[++idx]);
		cout << pre << endl;
	}
}
