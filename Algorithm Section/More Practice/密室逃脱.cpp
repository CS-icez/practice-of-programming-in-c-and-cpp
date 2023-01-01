#include <bits/stdc++.h>
using namespace std;

const int N = 111;
const int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
int mp[N][N];
int vis[N][N];

struct Clue{
	int x, y, id;
	bool operator<(const Clue& t) const{
		return id < t.id;
	}
};
Clue key[N*N];
int cnt;

queue<pair<int, int>> q;
int xe = 1, ye = 1;

bool bfs(){
	while (!q.empty()){
		auto pre = q.front();
		q.pop();
		for (int i = 0, x, y; i < 4; ++i){
			x = pre.first+dx[i], y = pre.second+dy[i];
			if (!mp[x][y] || ~vis[x][y]) continue;
			vis[x][y] = vis[pre.first][pre.second]+1;
			q.push({x, y});
			if (x == xe && y == ye) return true;
		}
	}
	return false;
}

int main(){
	int T;
	cin >> T;
	while (T--){
		memset(mp, 0, sizeof mp);
		memset(vis, -1, sizeof vis);
		memset(key, 0, sizeof key);
		xe = ye = 1;
		cnt = 0;
		
		int m, n;
		cin >> m >> n;
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j){
				cin >> mp[i][j];
				if (mp[i][j] > 1)
					key[cnt++] = {i, j, mp[i][j]};
			}
		sort(key, key+cnt);
			
		int xs, ys, f = 0, res = 0;
		
		for (int i = 0; i < cnt && !f; ++i){
			xs = xe, ys = ye;
			xe = key[i].x, ye = key[i].y;
			
			if (xs == xe && ys == ye) continue;
			
			q = queue<pair<int, int>>();
			memset(vis, -1, sizeof vis);
			
			vis[xs][ys] = 0;
			q.push({xs, ys});
			
			if (bfs()) res += vis[xe][ye];
			else f = 1;
		}
		
		cout << (f? -1: res) << endl;
	}
}
