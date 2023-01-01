#include <bits/stdc++.h>
using namespace std;

const int N = 111;
int n;
int p[N][N];
int sum[N][N];
bool ctrl[N][N];

using pii = pair<int, int>;
#define x first
#define y second
queue<pii> q;

void bfs(){
	while (!q.empty()){
		int a = q.front().x, b = q.front().y;
		q.pop();
		
		for (int i = 1; i <= n; ++i)
			if (p[b][i] && !ctrl[a][i]){
				sum[a][i] += p[b][i];
				if (sum[a][i] > 50)
					ctrl[a][i] = 1, q.push({a, i});
			}		
	}
}

int main(){
	cin >> n;
	for (int i = 1, a, b; i <= n; ++i){
		cin >> a >> b >> p[a][b];
		sum[a][b] = p[a][b];
		if (p[a][b] > 50)
			ctrl[a][b] = 1, q.push({a, b});
	}
	
	for (int i = 1; i <= n; ++i)
		ctrl[i][i] = 1;
			
	bfs();
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j && ctrl[i][j])
				cout << i << " " << j << endl;
}
