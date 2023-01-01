#include <bits/stdc++.h>
using namespace std;

const int N = 17;
struct Node{
	int num, id;
	bool operator<(const Node& t){
		return num < t.num;
	}
};
Node temp[N];
int ori[N], n;
int best;

int calcMinStep(int src[]){
	int cnt = 0;
	for (int i = 2; i <= n; ++i)
		if (src[i] != src[i-1]+1) ++cnt;
	return (cnt+1)/2;
}

void trans(int src[], int dst[], int first, int last, int pre){
	for (int i = first; i <= last; ++i)
		dst[pre+i+1-first] = src[i];
	for (int i = pre+1; i < first; ++i)
		dst[last-first+1+i] = src[i];
}

void dfs(int src[], int step){
	int t = calcMinStep(src);
	if (step+t >= best) return;
	if (!t){
		best = step;
		return;
	}
	
	int cur[N];
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			for (int k = 0; k < i-1; ++k){
				memcpy(cur, src, sizeof cur);
				trans(src, cur, i, j, k);
				dfs(cur, step+1);
			}	
}

int main(){
	int T;
	cin >> T;
	for (int Case = 1; Case <= T; ++Case){
		cin >> n;
		for (int i = 1; i <= n; ++i){
			cin >> ori[i];
			temp[i] = {ori[i], i};
		}
		
		sort(temp+1, temp+n+1);
		for (int i = 1; i <= n; ++i)
			ori[temp[i].id] = i;	
		
		best = 6;
		dfs(ori, 0);
		printf("Case #%d: ", Case);
		if (best <= 5) printf("%d\n", best);
		else puts("Can not finish in 5 steps");
	}
}
