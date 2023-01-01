#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 23;
const int dx[]{-1, 1, 0, 0}, dy[]{0, 0, 1, -1};
int m, n;
char mp[N][N];
int key[N][N], st;
int lock[5], cnt;
bool vis[N][N];

struct Node{
	int x, y;
};
queue<Node> q;

bool bfs(){
	if (q.empty()) return false;
	
	while (!q.empty()){
		Node pre = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i){
			Node cur = pre;
			cur.x += dx[i], cur.y += dy[i];
			
			if (mp[cur.x][cur.y] == 'G') return true;
			
			if (mp[cur.x][cur.y] == 'X') continue;
			if (mp[cur.x][cur.y] >= 'A' && mp[cur.x][cur.y] <= 'E')
				continue;
			
			st |= key[cur.x][cur.y];
			if (vis[cur.x][cur.y]) continue;		
			
			vis[cur.x][cur.y] = 1;
			q.push(cur);
		}
	}
	
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j){
			if (mp[i][j] < 'A' || mp[i][j] > 'E') continue;
			if (vis[i][j]) continue;
			if ((st&lock[mp[i][j]-'A']) != lock[mp[i][j]-'A']) continue;
			
			int f = 0;
			for (int k = 0; k < 4; ++k)
				if (vis[i+dx[k]][j+dy[k]]){
					f = 1;
					break;
				}
				
			if (!f) continue;
			vis[i][j] = 1;
			q.push({i, j});
		}
				
	
	return bfs();
}

int main(){
	while (cin >> m >> n, m){
		memset(mp, 'X', sizeof mp);
		memset(lock, 0, sizeof lock);
		memset(key, 0, sizeof key);
		memset(vis, 0, sizeof vis);
		cnt = 0;
		q = queue<Node>();
		st = 0;
		
		int xs, ys;
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j){
				cin >> mp[i][j];
				switch (mp[i][j]){
					case 'S': xs = i, ys = j; break;
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e': 
						lock[mp[i][j]-'a'] |= 1<<cnt;
						key[i][j] = 1<<cnt; 
						++cnt;
						break;
				}
			}
			
		q.push({xs, ys});
		vis[xs][ys] = 1;
		
		puts(bfs()? "YES": "NO");
	}
}
