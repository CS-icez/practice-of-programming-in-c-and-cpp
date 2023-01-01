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

const int N = 13;
const int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
bool avi[N][N];
int vis[N][N];
int xs, ys, xe, ye, T;
queue<pair<int, int>> q;

bool bfs(){
	while (!q.empty()){
		auto pre = q.front();
		if (vis[pre.x][pre.y] == T) break;
		q.pop();
		
		for (int i = 0, x1, y1; i < 4; ++i){
			x1 = pre.x+dx[i], y1= pre.y+dy[i];
			if (!avi[x1][y1] || ~vis[x1][y1]) continue;
			
			vis[x1][y1] = vis[pre.x][pre.y]+1;
			q.push({x1, y1});
			if (x1 == xe && y1 == ye) return true;
		}
	}
	return false;
}

int main(){
	int K;
	cin >> K;
	
	while (K--){
		memset(avi, 0, sizeof avi);
		memset(vis, -1, sizeof vis);
		q = queue<pair<int, int>>();
		
		int n;
		cin >> n >> T;
		char ch;
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j){
				cin >> ch;
				switch (ch){
					case '#': break;
					case '.': avi[i][j] = 1; break;
					case 'S': avi[i][j] = 1, xs = i, ys = j; break;
					case 'E': avi[i][j] = 1, xe = i, ye = j; break;
				}
			}
			
		vis[xs][ys] = 0;
		q.push({xs, ys});
		puts(bfs()? "YES": "NO");
	}
}
