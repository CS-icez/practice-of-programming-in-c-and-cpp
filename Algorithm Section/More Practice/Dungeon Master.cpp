#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 33;
const int dx[]{1, -1, 0, 0, 0, 0},
		dy[]{0, 0, 1, -1, 0, 0},
		dz[]{0, 0, 0, 0, -1, 1};
char mp[N][N][N];
int vis[N][N][N];
int r, c, l;
struct Node{
	int x, y, z;
};
queue<Node> q;

void bfs(){
	while (!q.empty()){
		Node pre = q.front();
		q.pop();
		
		for (int i = 0; i < 6; ++i){
			Node cur = pre;
			cur.x += dx[i], cur.y += dy[i], cur.z += dz[i];
			if (mp[cur.x][cur.y][cur.z] == '#' || ~vis[cur.x][cur.y][cur.z])
				continue;
			
			vis[cur.x][cur.y][cur.z] = vis[pre.x][pre.y][pre.z]+1;	
			q.push(cur);
			if (mp[cur.x][cur.y][cur.z] == 'E'){
				printf("Escaped in %d minute(s).\n", vis[cur.x][cur.y][cur.z]);
				return;
			}
		}
	}
	
	printf("Trapped!\n");
}

int main(){
	while (cin >> l >> r >> c, r){
		memset(mp, '#', sizeof mp);
		memset(vis, -1, sizeof vis);
		q = queue<Node>();
		
		int xs, ys, zs;
		for (int k = 1; k <= l; ++k)
			for (int i = 1; i <= r; ++i)
				for (int j = 1; j <= c; ++j){
					cin >> mp[i][j][k];
					if (mp[i][j][k] == 'S')
						xs = i, ys = j, zs = k;
				}
				
		q.push({xs, ys, zs});
		vis[xs][ys][zs] = 0;
		bfs();
	}
}
