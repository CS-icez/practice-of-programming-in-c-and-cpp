#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 110, M = 12;
int n, m;
vector<int> avi1, avi2[1<<M];
int dp[2][1<<M][1<<M];
int hill[N];

#define cnt(i) __builtin_popcount(i)

void init_avi1(){
	for (int i = 0; i < (1<<m); ++i)
		if (!(i>>1&i) && !(i>>2&i))
			avi1.push_back(i);
}

void init_avi2(){
	for (auto i: avi1)
		for (auto j: avi1)
			if (!(i&j)) 
				avi2[i].push_back(j);
}

int main(){
	cin >> n >> m;
	init_avi1();
	init_avi2();
	
	char c;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < m; ++j){
			cin >> c;
			hill[i] |= (c=='H')<<j;
		}
	
	for (int i = 1; i <= n+2; ++i){	//handle line i
		for (int j: avi1){	//line i-2
			if (j&hill[i-2]) continue;
			for (int k: avi2[j]){	//line i-1
				if (k&hill[i-1]) continue;
				for (int l: avi2[k]){	//line i
					if (l&hill[i]) continue;
					if (l&j) continue;
					dp[i&1][l][k] = max(dp[i&1][l][k], dp[(i-1)&1][k][j]+cnt(l));
				}
			}
		}	
	}
	
	printf("%d", dp[(n+2)&1][0][0]);
}
