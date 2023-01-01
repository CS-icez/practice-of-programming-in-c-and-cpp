#include <iostream>
#include <cstring>
using namespace std;

#define int long long

const int N = 23;
int n, c;
int dp[N][N][2];	//total, first, greater
bool flag[N];

int re(int x){
	int cnt = 0;
	for (int i = 1; i <= x; ++i)
		if (!flag[i]) ++cnt;
	return cnt;
}

signed main(){
	int K;
	cin >> K;
	
	dp[1][1][0] = dp[1][1][1] = 1;
	
	for (int i = 2; i < N; ++i){
		for (int j = 1; j <= i; ++j){
			for (int k = 1; k < j; ++k)
				dp[i][j][0] += dp[i-1][k][1];
			for (int k = j+1; k <= i; ++k)
				dp[i][j][1] += dp[i-1][k-1][0];
		}
	}
	
	while (K--){
		cin >> n >> c;
		int pre = 0, f;
		memset(flag, 0, sizeof flag);
		
		for (int i = 1; i <= n; ++i){
			if (dp[n][i][0] >= c){
				cout << i;
				flag[i] = 1;
				pre = i, f = 1;
				break;
			}
			c -= dp[n][i][0];
			if (dp[n][i][1] >= c){
				cout << i;
				flag[i] = 1;
				pre = i, f = 0;
				break;
			}
			c -= dp[n][i][1];
		}
		
		for (int i = n-1; i > 1; --i){	//i个数，第n-i+1位
			if (f){
				for (int j = 1; j < pre; ++j){
					if (flag[j]) continue;
					int r = re(j);
					if (dp[i][r][1] >= c){
						cout << " " << j;
						flag[j] = 1;
						pre = j, f = 0;
						break;
					}
					c -= dp[i][r][1];
				}
			}
			else{
				for (int j = pre+1; j <= n; ++j){
					if (flag[j]) continue;
					int r = re(j);
					if (dp[i][r][0] >= c){
						cout << " " << j;
						flag[j] = 1;
						pre = j, f = 1;
						break;
					}
					c -= dp[i][r][0];
				}
			}
		}
		for (int i = 1; i <= n; ++i)
			if (!flag[i]){
				cout << " " << i;
				break;
			}
		cout << endl;
	}
}
