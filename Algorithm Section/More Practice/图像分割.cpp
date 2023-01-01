#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <queue>
using namespace std;

#define x first
#define y second

const int N = 267;
int m;
const int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
int mp[N][N];
bool vis[N][N];
queue<pair<int, int>> q;

void bfs(){
	while (!q.empty()){
		auto pre = q.front();
		q.pop();
		
		for (int i = 0, x1, y1; i < 4; ++i){
			x1 = pre.x+dx[i], y1 = pre.y+dy[i];
			if (vis[x1][y1]) continue;
			if (abs(mp[x1][y1]-mp[pre.x][pre.y]) > m) continue;
			vis[x1][y1] = 1;
			q.push({x1, y1});
		}
	}
}

int main(){
	int h, w;
	while (cin >> h >> w >> m, h){
		memset(mp, 0x3f, sizeof mp);
		memset(vis, 0, sizeof vis);
		
		for (int i = 1; i <= h; ++i)
			for (int j = 1; j <= w; ++j)
				cin >> mp[i][j];
				
		int cnt = 0;
		for (int i = 1; i <= h; ++i)
			for (int j = 1; j <= w; ++j)
				if (!vis[i][j]){
					++cnt;
					q.push({i, j});
					vis[i][j] = 1;
					bfs();
				} 
		
		cout << cnt << endl;
	}
}
