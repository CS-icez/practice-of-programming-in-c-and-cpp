#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int s, n, m;
int num[19];
int col[166];

bool dfs(int x, int y){
	if (x == s+1) return true;
	if (col[y] >= x) return y == s? dfs(x+1, 1): dfs(x, y+1);
		
	for (int i = m; i; --i){
		if (!num[i]) continue;
		if (x+i > s+1 || y+i > s+1) continue;
		
		int f = 0;
		for (int j = 0; j < i; ++j)
			if (col[y+j] >= x){
				f = 1;
				break;
			}
		if (f) continue;
		
		for (int j = 0; j < i; ++j)
			col[y+j] += i;
		--num[i];
		
		if (y == s? dfs(x+1, 1): dfs(x, y+1)) return true;
		
		for (int j = 0; j < i; ++j)
			col[y+j] -= i;
		++num[i];
	}
	
	return false;
}

int main(){
	int T;
	cin >> T;
	
	while (T--){
		memset(col, 0, sizeof col);
		memset(num, 0, sizeof num);
		
		cin >> s >> n;
		
		int cnt = 0, a = 0;
		for (int i = 0, t; i < n; ++i){
			cin >> t;
			++num[t];
			a += t*t;
			cnt += t>s/2;
			m = max(t, m);
		}
			
		if (cnt > 1 || a != s*s){
			cout << "NO" << endl;
			continue;
		}	
		
		puts(dfs(1, 1)? "YES": "NO");
	}
}
