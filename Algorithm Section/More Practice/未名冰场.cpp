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

const int N = 111;
const int dx[]{-1, -1, -1, 0, 0, 1, 1, 1},
		dy[]{-1, 0, 1, -1, 1, -1 ,0, 1};
bool avi[N][N];
int vis[N][N];
queue<pair<int, int>> q;

void bfs(){
	while (!q.empty()){
		auto pre = q.front();
		q.pop();
		
		for (int i = 0, x, y; i < 8; ++i){
			x = pre.first+dx[i], y = pre.second+dy[i];
			if (!avi[x][y] || vis[x][y]) continue;
			vis[x][y] = 1;
			q.push({x, y});
		}
	}
}

int main(){
	int m, n;
	while (cin >> n >> m, n){
		memset(avi, 0, sizeof avi);
		memset(vis, 0, sizeof vis);
		int cnt = 0;
		
		char ch;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j){
				cin >> ch;
				avi[i][j] = (ch=='@');
			}
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (avi[i][j] && !vis[i][j]){
					++cnt;
					vis[i][j] = 1;
					q.push({i, j});
					bfs();
				}
		
		cout << cnt << endl;
	}
}
