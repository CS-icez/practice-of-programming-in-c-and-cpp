#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

const int N = 505;
const int dx[]{-1, 1, 0, 0}, dy[]{0, 0, -1, 1};
int r, c;
int mp[N][N];	//1 for 'X'
int vis[N][N];

void f(int x, int y){
	for (int i = 0, x1, y1; i < 4; ++i){
		x1 = x+dx[i], y1 = y+dy[i];
		if (x1 < 0 || y1 < 0 || x1 >= r || y1 >= c)
			continue;
		if (vis[x1][y1] || mp[x1][y1]) continue;
		vis[x1][y1] = 1;
		f(x1, y1);
	}
}

int main(){
	int T;
	cin >> T;
	
	while (T--){
		cin >> r >> c;
		
		memset(vis, 0, sizeof vis);
		
		char t;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j){
				cin >> t;
				mp[i][j] = t=='X';
			}
		
		for (int i = 0; i < r; ++i){
			if (!mp[i][0])
				vis[i][0] = 1, f(i, 0);
			if (!mp[i][c-1])
				vis[i][c-1] = 1, f(i, c-1);
		}
		for (int j = 0; j < c; ++j){
			if (!mp[0][j])
				vis[0][j] = 1, f(0, j);
			if (!mp[r-1][j])
				vis[r-1][j] = 1, f(r-1, j);
		}
		
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j)
				if (vis[i][j]) cout << 'O';
				else cout << 'X';
			cout << endl;
		}
		cout << endl;
	}
}
