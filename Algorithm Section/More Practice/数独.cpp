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

const int N = 11;
int mp[N][N];
bool row[N][N], col[N][N], grid[N][N];

bool dfs(int x, int y){
	if (x == -1) return true;
	if (mp[x][y])
		return y? dfs(x, y-1): dfs(x-1, 8);
	
	int idx = x/3*3+y/3;
	for (int k = 1; k <= 9; ++k){
		if (row[x][k] || col[y][k] || grid[idx][k])
			continue;
		mp[x][y] = k;
		row[x][k] = col[y][k] = grid[idx][k] = 1;
		if (y? dfs(x, y-1): dfs(x-1, 8)) return true;
		row[x][k] = col[y][k] = grid[idx][k] = 0;
		mp[x][y] = 0;
	}
	return false;
}

int main(){
	int T;
	cin >> T;
	while (T--){
		for (int i = 0; i < 9; ++i)
			for (int j = 1; j <= 9; ++j)
				row[i][j] = col[i][j] = grid[i][j] = 0;
		
		for (int i = 0, t; i < 9; ++i)
			for (int j = 0; j < 9; ++j){
				scanf("%1d", &t);
				mp[i][j] = t;
				row[i][t] = col[j][t] = grid[i/3*3+j/3][t] = 1;
			}
			
		dfs(8, 8);	
		
		for (int i = 0; i < 9; puts(""), ++i)
			for (int j = 0; j < 9; ++j)
				cout << mp[i][j];
	}
}
