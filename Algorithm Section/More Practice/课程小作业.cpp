#include <bits/stdc++.h>
using namespace std;

struct Course{
	int v, t;
	bool operator<(const Course& a){
		return v > a.v;
	}
};

const int N = 10011;
Course c[N];
bool vis[N];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> c[i].v >> c[i].t;
	sort(c+1, c+n+1);
	
	int res = 0;
	for (int i = 1; i <= n; ++i){
		int f = 0;
		for (int j = c[i].t; j && !f; --j)
			if (!vis[j]) f = j;
		if (f)
			vis[f] = 1, res += c[i].v;
	}
	cout << res;
}
