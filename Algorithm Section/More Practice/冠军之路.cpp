#include <bits/stdc++.h>
using namespace std;

const int N = 111;
const int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
char mp[N][N];
int vis[N][N][1<<8];
int oppo[N][N], cnt, dst;

struct Node{
	int x, y, st;
};
queue<Node> q;

bool avi(int x, int y){
	return mp[x][y] != '#' && mp[x][y] != 'w'
		&& mp[x][y] != 'a' && mp[x][y] != 's'
		&& mp[x][y] != 'd';
}

void bfs(){
	while (!q.empty()){
		Node pre = q.front();
		q.pop();
		int x = pre.x, y = pre.y, st = pre.st;
		for (int i = 0; i < 4; ++i){
			int x1 = x+dx[i], y1 = y+dy[i], st1 = st;
			if (!avi(x1, y1)) continue;
			st1 |= oppo[x1][y1];
			if (vis[x1][y1][st1]) continue;
			vis[x1][y1][st1] = vis[x][y][st]+1;
			q.push({x1, y1, st1});
			if (mp[x1][y1] == 'O' && st1 == dst){
				cout << vis[x1][y1][st1]-1;
				return;
			}
		}
	}
	cout << -1;
}

int main(){
	int n, m;
	cin >> n >> m;
	memset(mp, '#', sizeof mp);
	
	int xs, ys;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j){
			cin >> mp[i][j];
		}
		
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			switch (mp[i][j]){
				case 'I':
					xs = i, ys = j;
					break;
				case 'O':
				case '#':
				case '.':
					break;
				case 'w':
					for (int k = i-1; k; --k)
						if (avi(k, j)) oppo[k][j] |= 1<<cnt;
						else break;
					dst |= 1<<cnt;
					++cnt;
					break;
				case 'a':
					for (int k = j-1; k; --k)
						if (avi(i, k)) oppo[i][k] |= 1<<cnt;
						else break;
					dst |= 1<<cnt;
					++cnt;
					break;
				case 's':
					for (int k = i+1; k <= n; ++k)
						if (avi(k, j)) oppo[k][j] |= 1<<cnt;
						else break;
					dst |= 1<<cnt;
					++cnt;	
					break;
				case 'd':
					for (int k = j+1; k <= m; ++k)
						if (avi(i, k)) oppo[i][k] |= 1<<cnt;
						else break;
					dst |= 1<<cnt;
					++cnt;	
					break;			
			}
	
	vis[xs][ys][oppo[xs][ys]] = 1;
	q.push({xs, ys, oppo[xs][ys]});	
	bfs();
}
