#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 111, M = 11;
int n, m;
const int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
int xe, ye, xs, ys;
char mp[N][N];
bool vis[N][N][M];
int sn[N][N];

struct Node{
	int x, y, k, s, tim;	//has got k
	bool operator<(const Node& t) const{
		return tim > t.tim;	//note >
	}
};

priority_queue<Node> q;

void BFS(){
	while (!q.empty()){
		Node cur = q.top();
		if (cur.x == xe && cur.y == ye && cur.k == m){
			cout << cur.tim << endl;
			return;
		}
		q.pop();
		
		for (int i = 0; i < 4; ++i){
			Node nxt = cur;
			nxt.x += dx[i], nxt.y += dy[i];
			if (nxt.x < 0 || nxt.y < 0 || nxt.x >= n || nxt.y >= n)
				continue;
			if (mp[nxt.x][nxt.y] == '#')
				continue;
				
			if (mp[nxt.x][nxt.y] == cur.k+1+'0') nxt.k += 1;
			if (vis[nxt.x][nxt.y][nxt.k]) continue;
			vis[nxt.x][nxt.y][nxt.k] = 1;
			
			nxt.tim += 1;
			if (mp[nxt.x][nxt.y] == 'S' && (cur.s&sn[nxt.x][nxt.y]) == 0){	//== is prior than &
				nxt.tim += 1;
				nxt.s |= sn[nxt.x][nxt.y];
			}
			q.push(nxt);
		}
	}
	cout << "impossible" << endl;
}

int main(){
	while (cin >> n >> m, n){
		q = priority_queue<Node>();
		memset(vis, 0, sizeof vis);
		memset(sn, 0, sizeof sn);
		
		for (int i = 0, cnt = 0; i < n; ++i)
			for (int j = 0; j < n; ++j){
				cin >> mp[i][j];
				switch (mp[i][j]){
					case 'K': xs = i, ys = j; break;
					case 'T': xe = i, ye = j; break;
					case 'S': sn[i][j] |= 1<<(cnt++); break;
					default: break;
				}	
			}
		
		vis[xs][ys][0] = 1;
		q.push({xs, ys, 0, 0, 0});
		
		BFS();	
	}
}
