#include <bits/stdc++.h>
using namespace std;

using U = __uint128_t;
const int N = 19, M = 111;
int n, m;
U mp[N];
U cur[N];
int best;

void dfs(){
	for (int i = 0; i < (1<<n); ++i){
		memcpy(cur, mp, sizeof cur);
		for (int j = 0; j < n; ++j)
			if (i&(U(1)<<j)) cur[j] ^= U(-1);
		int res = 0;
		for (int j = 0; j < m; ++j){
			int cnt = 0;
			for (int k = 0; k < n; ++k)
				if (cur[k]&(U(1)<<j)) ++cnt;
			res += max(cnt, n-cnt);
		}
		best = max(best, res);
	}
}

int main(){
	int T;
	cin >> T;
	while (T--){
		memset(mp, 0, sizeof mp);
		best = 0;
		
		cin >> n >> m;
		for (int i = 0, t; i < n; ++i)
			for (int j = 0; j < m; ++j){
				cin >> t;
				if (t) mp[i] |= U(1)<<j;
			}
			
		dfs();
		cout << best << endl;
	}
}
