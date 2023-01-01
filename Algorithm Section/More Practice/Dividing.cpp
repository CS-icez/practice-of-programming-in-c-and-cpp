#include <iostream>
using namespace std;

const int N = 20011;
int n;
int v[N], dp[6*N];
int sum;

int main(){
	int T = 0;
	while (++T){
		int f = 0;
		sum = n = 0;
		for (int i = 1, t; i <= 6; ++i){
			cin >> t;
			sum += i*t;
			if (t) f = 1;
			
			int k = 1;
			while (k <= t){
				v[++n] = k*i;
				t -= k;
				k <<= 1;
			}
			if (t) v[++n] = t*i;
		}
		if (!f) return 0;
		
		printf("Collection #%d:\n", T);
		if (sum&1){
			printf("Can't be divided.\n\n");
			continue;
		}
		sum /= 2;
		
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		
		for (int i = 1; i <= n; ++i)
			for (int j = sum; j >= v[i]; --j)
				dp[j] += dp[j-v[i]];
				
		
		puts(dp[sum]? "Can be divided.\n": "Can't be divided.\n");
	}
}
