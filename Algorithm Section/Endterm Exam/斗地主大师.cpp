#include <bits/stdc++.h>
using namespace std;

#define int long long

int p, q, x, y;

map<int, int> m;
int best = 53;

bool dfs(int cur, int step){
	if (step >= best) return false;
	if (cur == q){
		best = step;
		return true;
	}
	
	int nxt = cur-x;
	if (nxt >= 0 && (!m.count(nxt) || m[nxt] > step+1)){
		m[nxt] = step+1;
		if (dfs(nxt, step+1)) return true;
	}
		
	
	nxt = cur*y;
	if (nxt < q+52*x && (!m.count(nxt) || m[nxt] > step+1)){
		m[nxt] = step+1;
		if (dfs(nxt, step+1)) return true;
	}
		
	
	return false;
}

signed main(){
	cin >> p >> q >> x >> y;
	m[p] = 0;
	if (dfs(p, 0)) cout << best;
	else cout << "Failed";
}
