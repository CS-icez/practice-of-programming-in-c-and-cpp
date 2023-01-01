#include <bits/stdc++.h>
using namespace std;

const int N = 23, K = 111;
const int dx[]{1, 0, -1, 0}, dy[]{0, 1, 0, -1};
int m, n, k;
int mp[N][N];
int vis[K];
int step;

void f(int x, int y, int s){
	step = max(step, s);
	
	for (int i = 0, x1, y1, t; i < 4; ++i){
		x1 = x+dx[i], y1 = y+dy[i];
		t = mp[x1][y1];
		if (vis[t]) continue;
		vis[t] = true;
		f(x1, y1, s+1);
		vis[t] = false;
	}
}

int main(){
	cin >> m >> n >> k;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> mp[i][j];
	
	vis[0] = 1, vis[mp[1][1]] = 1;	
	f(1, 1, 1);
	cout << step;
}
