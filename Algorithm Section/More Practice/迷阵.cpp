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

struct Node{
	int x, y, h;
};

const int N = 265, H = 7;
const int dx[]{1, 0, 0, -1}, dy[]{0, 1, -1, 0};
int m, n, h;
char mp[N][N];
int vis[N][N][H];
queue<Node> q;

void bfs(){
	while (!q.empty()){
		Node pre = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i){
			Node cur = pre;
			cur.x += dx[i], cur.y += dy[i];
			if (mp[cur.x][cur.y] == '#') continue;
			if (mp[cur.x][cur.y] == '*') cur.h -= 1;
			if (!cur.h) continue;	//note
			if (~vis[cur.x][cur.y][cur.h]) continue;	//note ~
			vis[cur.x][cur.y][cur.h] = vis[pre.x][pre.y][pre.h]+1;
			q.push(cur);
			if (cur.x == m && cur.y == n){
				cout << vis[cur.x][cur.y][cur.h] << endl;
				return;
			}
		}
	}
}

int main(){
	int T;
	cin >> T;
	while (T--){
		memset(mp, '#', sizeof mp);
		memset(vis, -1, sizeof vis);
		q = queue<Node>();
		
		cin >> m >> n >> h;
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				cin >> mp[i][j];
				
		vis[1][1][h] = 0;
		q.push({1, 1, h});
		bfs();
	}
}
