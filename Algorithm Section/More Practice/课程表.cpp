#include <bits/stdc++.h>
using namespace std;

const int N = 1011, M = 4011;
int n, m;
vector<int> pre[N];
int nvis[N];
queue<int> q;

bool solve(){
	while (!q.empty()){
		unsigned len = q.size();
		
		for (unsigned i = 0; i < len; ++i){
			int t = q.front();
			q.pop();
			
			int f = 0;
			for (int j = pre[t].size()-1; ~j && !f; --j)
				if (nvis[pre[t][j]]) f = 1;
			
			if (f) q.push(t);
			else nvis[t] = 0;
		}
		
		if (q.size() == len) break;
	}
	
	return q.empty();
}

int main(){
	while (cin >> n >> m){
		memset(nvis, 0, sizeof nvis);
		q = queue<int>();
		for (int i = 0; i < n; ++i)
			pre[i].clear();
		
		int a, b;
		while (m--){
			cin >> a >> b;
			nvis[a] = 1;
			pre[a].push_back(b);
			q.push(a);
		}

		puts(solve()? "True": "False");
	}
}
