#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

const int N = 13;
int n;
bool avi[N][N];
bool vis[N];

bool dfs(int pos){
	if (pos == n) return true;
	for (int i = n; i; --i){
		if (i == pos) continue;
		if (!avi[pos][i] || vis[i]) continue;
		vis[i] = 1;
		if (dfs(i)) return true;
	}
	return false;
}

int main(){
	int T;
	cin >> T;
	
	while (T--){
		memset(vis, 0, sizeof vis);
		
		cin >> n;
		for (int i = 1, t; i <= n; ++i)
			for (int j = 1; j <= n; ++j){
				cin >> t;
				avi[i][j] = ~t;
			}
			
		vis[1] = 1;
		puts(dfs(1)? "YES": "NO");
	}
}
