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
const int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
int n, m;
char mp[N][N];
int vis[N][N];

using pii = pair<int, int>;
map<pii, pii> tran;
map<char, pii> book;
queue<pii> q;

bool bfs(){
	while (!q.empty()){
		pii pre = q.front();
		q.pop();
		
		if (mp[pre.first][pre.second] >= 'a' && mp[pre.first][pre.second] <= 'z'){
			pii nxt = tran[pre];
			if (!~vis[nxt.first][nxt.second]){
				vis[nxt.first][nxt.second] = vis[pre.first][pre.second]+1;
				q.push(nxt);
			}	
		}
		
		for (int i = 0, x, y; i < 4; ++i){
			x = pre.first+dx[i], y = pre.second+dy[i];
			if (mp[x][y] == '#' || ~vis[x][y]) continue;
			
			vis[x][y] = vis[pre.first][pre.second]+1;
			q.push({x, y});
			if (mp[x][y] == 'I') return true;
		}
	}
	return false;
}

int main(){
	int T;
	cin >> T;
	
	for (int T1 = 1; T1 <= T; ++T1){
		//init
		memset(mp, '#', sizeof mp);
		memset(vis, -1, sizeof vis);
		tran.clear();
		book.clear();
		q = queue<pii>();
		
		cin >> n >> m;
		
		int xs, ys, xe, ye;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j){
				cin >> mp[i][j];
				if (mp[i][j] >= 'a' && mp[i][j] <= 'z'){
					char t = mp[i][j];
					if (book.count(t)){
						tran[book[t]] = {i, j};
						tran[{i, j}] = book[t];
					}
					else book[t] = {i, j};
				}
				if (mp[i][j] == 'B') xs = i, ys = j;
				if (mp[i][j] == 'I') xe = i, ye = j;
			}
		
		vis[xs][ys] = 0;
		q.push({xs, ys});
		cout << "Case #" << T1 << ": ";
		cout << (bfs()? vis[xe][ye]: -1) << endl;
	}
}
