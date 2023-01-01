#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

const int N = 23;
int n, w;
int c[N];
int bag[N], cnt;
int ans;

void dfs(int idx){
	if (cnt > ans) return;
	
	if (!idx){
		ans = min(ans, cnt);
		return;
	}
	
	for (int i = 0; i < cnt; ++i)
		if (bag[i] >= c[idx]){
			bag[i] -= c[idx];
			dfs(idx-1);
			bag[i] += c[idx];
		}
	
	bag[cnt++] = w-c[idx];
	dfs(idx-1);
	--cnt;
}

int main(){
	cin >> n >> w;
	ans = n;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	sort(c+1, c+n+1);
	dfs(n);
	cout << ans;
}
