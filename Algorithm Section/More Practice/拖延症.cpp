#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

const int N = 19;
int vis[2];
int w[N], s[N];
int best;

void dfs(int day, int spt, int val){
	if (day == 16){
		if (vis[1] >= vis[0])
			best = max(best, val);
		return;
	}
	if (vis[0] > 5) return;
	
	if (spt >= s[day]){
		++vis[day>10];
		dfs(day+1, spt-s[day], val+w[day]);
		--vis[day>10];
	}
	dfs(day+1, spt, val);
}

int main(){
	int t;
	cin >> t;
	for (int i = 1; i <= 15; ++i)
		cin >> w[i] >> s[i];
	dfs(1, t, 0);
	cout << best;
}
