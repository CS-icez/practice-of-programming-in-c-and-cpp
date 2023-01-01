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
#include <set>
using namespace std;

const int N = 111, M = 11;
int n, m;
const int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
int xe, ye, xs, ys, k;
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
		if (cur.x == xe && cur.y == ye && cur.k == k){
			cout << cur.tim << endl;
			return;
		}
		q.pop();
		
		for (int i = 0; i < 4; ++i){
			Node nxt = cur;
			nxt.x += dx[i], nxt.y += dy[i];
			if (nxt.x < 0 || nxt.y < 0 || nxt.x >= n || nxt.y >= n)
				continue;
			if (mp[nxt.x][nxt.y] == 'X')
				continue;
				
			nxt.tim += 1;
			if (mp[nxt.x][nxt.y] == 'G' && (cur.s&sn[nxt.x][nxt.y]) == 0){
				nxt.tim += 1;
				nxt.s |= sn[nxt.x][nxt.y];
			}
			
			if (mp[nxt.x][nxt.y] == cur.k+1+'0') nxt.k += 1;
			if (vis[nxt.x][nxt.y][nxt.k]) continue;
			vis[nxt.x][nxt.y][nxt.k] = 1;
			
			q.push(nxt);
		}
	}
}

int main(){
	cin >> n >> m;

	for (int i = 0, cnt = 0; i < n; ++i)
		for (int j = 0; j < m; ++j){
			cin >> mp[i][j];
			switch (mp[i][j]){
				case 'S': xs = i, ys = j; break;
				case 'T': xe = i, ye = j; break;
				case 'G': sn[i][j] |= 1<<(cnt++); break;
				default: break;
			}
			if (mp[i][j] >= '1' && mp[i][j] <= '9')
				k = max(k, mp[i][j]-'0');
		}
	
	vis[xs][ys][0] = 1;
	q.push({xs, ys, 0, 0, 0});
	
	BFS();	
}
