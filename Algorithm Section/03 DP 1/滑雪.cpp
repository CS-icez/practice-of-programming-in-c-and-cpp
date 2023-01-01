#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110;
int r, c, h[N][N];
int dp[N][N];
const int dx[]{-1, 1, 0, 0}, dy[]{0, 0, -1, 1};

int f(int x, int y){
	if (~dp[x][y]) return dp[x][y];
	int res = 1;
	for (int i = 0; i < 4; ++i){
		int x1 = x+dx[i], y1 = y+dy[i];
		if (x1 < 0 || y1 < 0 || x1 >= r || y1 >= c) continue;
		if (h[x1][y1] >= h[x][y]) continue;
		res = max(res, f(x1, y1)+1);
	}
	return dp[x][y] = res;
}


int main(){
	memset(dp, -1, sizeof dp);
	cin >> r >> c;
	
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> h[i][j];
	
	int res = 0;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			res = max(res, f(i, j));
	
	cout << res;
}
