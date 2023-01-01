#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

const int N = 111, S = 1011, T = 2411;
int ticket[N];
int dp[T][S];

int calcTicket(int x){
	int res = 0;
	res += x/3*200; x %= 3;
	res += x/2*150; x %= 2;
	res += x*100;
	return res;
}

int main(){
	int m, n, s;	//days, items, total dollars
	cin >> m >> n >> s;
	
	string temp;
	
	ticket[1] = 100, ticket[2] = 150, ticket[3] = 200;
	for (int i = 4; i <= m; ++i)
		ticket[i] = ticket[i-3]+200;

	int ans = 0;
	
	for (int k = 1, h, t, c; k <= n; ++k){
		scanf("%d%d%d", &h, &c, &t);
		cin >> temp;
		if (temp[0] == 'u')
			for (int i = t; i <= 24*m; ++i){
				int u = s-ticket[(i+23)/24];
				if (u < 0) break;
				for (int j = c; j <= u; ++j)
					dp[i][j] = max(dp[i][j], dp[i-t][j-c]+h);
				ans = max(ans, dp[i][u]);
			}									
		else
			for (int i = 24*m; i >= t; --i){
				int u = s-ticket[(i+23)/24];
				if (u < 0) continue;	//note continue
				for (int j = u; j >= c; --j)
					dp[i][j] = max(dp[i][j], dp[i-t][j-c]+h);
				ans = max(ans, dp[i][u]);
 			}
		
	}
	cout << ans;
}
