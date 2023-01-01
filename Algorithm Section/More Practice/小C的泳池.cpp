#include <bits/stdc++.h>
using namespace std;

const int N = 333;
int n;
const int dx[]{1, -1 ,0, 0}, dy[]{0, 0, 1, -1};
int mp[N][N];
bool vis[N][N];

struct Point{
	int x, y;
};
queue<Point> q;

bool bfs(int T){
	q.push({1, 1});
	vis[1][1] = 1;
	
	while (!q.empty()){
		int x = q.front().x, y = q.front().y;
		q.pop();
		
		for (int i = 0, x1, y1; i < 4; ++i){
			x1 = x+dx[i], y1 = y+dy[i];
			if (mp[x1][y1] > T || vis[x1][y1])
				continue;
			vis[x1][y1] = 1;
			q.push({x1, y1});
			if (x1 == n && y1 == n) return true;
		}
	}
	
	return false;
}

int main(){
	int l, r = 0, mid;
	cin >> n;
	
	memset(mp, 0x3f, sizeof mp);
	memset(vis, -1, sizeof vis);
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j){
			cin >> mp[i][j];
			r = max(r, mp[i][j]);
		}
	
	l = mp[1][1];	
	while (l < r){
		mid = (l+r)>>1;
		memset(vis, 0, sizeof vis);
		q = queue<Point>();
		if (bfs(mid)) r = mid;
		else l = mid+1;
	}
	
	cout << r;
}
