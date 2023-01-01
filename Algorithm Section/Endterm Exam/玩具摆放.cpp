#include <bits/stdc++.h>
using namespace std;

int vis[1<<16];
queue<int> q;
int dst;

void output(int x){
	for (int i = 0; i < 16; ++i){
		cout << ((x>>i)&1);
		if (i%4 == 3) cout << endl;
	}
	cout << endl;
}

void bfs(){
	int cnt = 0;
	while (!q.empty()){
		int pre = q.front();
		q.pop();
//		cout << (cnt++) << endl;
		
		for (int i = 0; i < 16; ++i){
			if ((pre&(1<<i)) == 0) continue;
			
			int cur = pre;
			if (i%4 != 0 && ((pre&(1<<(i-1))) == 0)){
				cur ^= 1<<i, cur ^= 1<<(i-1);
				if (!vis[cur]){
					vis[cur] = vis[pre]+1;
					q.push(cur);
					
					if (cur == dst) return;
				}
			}
			
			cur = pre;
			if (i%4 != 3 && ((pre&(1<<(i+1))) == 0)){
				cur ^= 1<<i, cur ^= 1<<(i+1);
				if (!vis[cur]){
					vis[cur] = vis[pre]+1;
					q.push(cur);
					if (cur == dst) return;
				}
			}
			
			cur = pre;
			if (i > 3 && ((pre&(1<<(i-4))) == 0)){
				cur ^= 1<<i, cur ^= 1<<(i-4);
				if (!vis[cur]){
					vis[cur] = vis[pre]+1;
					q.push(cur);
					if (cur == dst) return;
				}
			}
			
			cur = pre;
			if (i < 12 && ((pre&(1<<(i+4))) == 0)){
//				output(cur);
				cur ^= 1<<i, cur ^= 1<<(i+4);
				if (!vis[cur]){
					vis[cur] = vis[pre]+1;
					q.push(cur);
	//				output(cur);
					if (cur == dst) return;
				}
			}
		}
	}
}

int main(){
	int ori = 0;
	for (int i = 0, t; i < 16; ++i){
		scanf("%1d", &t);
		if (t) ori |= 1<<i;
	}
	for (int i = 0, t; i < 16; ++i){
		scanf("%1d", &t);
		if (t) dst |= 1<<i;
	}
	
//	output(ori);
//	output(dst);
	
	q.push(ori);
	vis[ori] = 1;
	bfs();
	cout << (vis[dst]-1);
}
