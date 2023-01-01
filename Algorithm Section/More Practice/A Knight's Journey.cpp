#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

const int N = 33;
const int dx[]{-1, 1, -2, 2, -2, 2, -1, 1},
			dy[]{-2, -2, -1, -1, 1, 1, 2, 2};
int vis[N][N];
int p, q;
pair<int, int> path[N*N];

bool dfs(int x, int y, int hav){
	if (hav == p*q) return true;
	
	for (int i = 0, x1, y1; i < 8; ++i){
		x1 = x+dx[i], y1 = y+dy[i];
		if (x1 < 1 || y1 < 1 || x1 > p || y1 > q)
			continue;
		if (vis[x1][y1]) continue;
		
		vis[x1][y1] = 1;
		path[hav] = {x1, y1};
		if (dfs(x1, y1, hav+1)) return true;
		
		vis[x1][y1] = 0;
	}
	
	return false;
}

int main(){
	int n;
	cin >> n;
	
	for (int T = 1; T <= n; ++T){
		memset(vis, 0, sizeof vis);
		
		printf("Scenario #%d:\n", T);
		cin >> p >> q;

		int f = 0;
		for (int i = 1; i <= p; ++i){
			for (int j = 1; j <= q; ++j){
				path[0] = {i, j};
				vis[i][j] = 1;
				if (dfs(i, j, 1)){
					f = 1;
					break;
				}
				vis[i][j] = 0;
			}
			if (f) break;	
		}
		if (f){
			for (int i = 0; i < p*q; ++i)
				putchar(path[i].second+'A'-1), putchar(path[i].first+'0');
			putchar('\n');
		}
		else
			printf("impossible\n");
		cout << endl;
	}
}
