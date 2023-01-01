#include <iostream>
#include <cstring>
using namespace std;

int n, k;
int bar[10][10];
int col[10];
int cnt;

void dfs(int r, int hav){
	if (hav == k){
		++cnt;
		return;
	}
	
	if (r == n){
		return;
	}
	
	for (int i = 0; i < n; ++i){
		if (bar[r][i] || col[i]) continue;
		col[i] = 1;
		dfs(r+1, hav+1);
		col[i] = 0;
	}
	dfs(r+1, hav);
}

int main(){
	while (cin >> n >> k, ~n){
		cnt = 0;
		memset(col, 0, sizeof col);
		
		char c;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j){
				cin >> c;
				bar[i][j] = (c=='.');
			}
		
		dfs(0, 0);
		cout << cnt << endl;
	}
}
