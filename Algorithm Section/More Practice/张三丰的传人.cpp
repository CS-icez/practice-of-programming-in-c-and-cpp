#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

int ans[1011], cnt;

bool dfs(int s, double w, int beg){
	if (fabs(1.0/s-w) < 1e-6){
		ans[cnt++] = s;
		return true;
	}
	if (1.0/s > w) return false;
	
	for (; beg*2 <= s; ++beg){
		if (w < 1.0/beg) continue;
		ans[cnt++] = beg;
		if (dfs(s-beg, w-1.0/beg, beg)) return true;
		--cnt;
	}
	return false;
}

int main(){
	int m, s;
	scanf("%d", &m);
	
	while (m--){
		cnt = 0;
		
		scanf("%d", &s);
		
		if (!dfs(s, 1, 1))
			printf("-1\n");
		else{
			printf("%d", cnt);
			for (int i = 0; i < cnt; ++i)
				printf(" %d", ans[i]);
			putchar('\n');
		}	
	}
}
