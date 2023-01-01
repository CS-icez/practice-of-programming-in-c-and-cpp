#include <bits/stdc++.h>
using namespace std;

const int N = 111;
bool m[N][N];
int row[N], col[N];

int main(){
	int n;
	cin >> n;
	for (int i = 1, t; i <= n; ++i)
		for (int j = 1; j <= n; ++j){
			cin >> t;
			if (t) ++row[i], ++col[j];
		}

	int x = 0, y = 0, f = 0;
	for (int i = 1; i <= n && !f; ++i){
		if (row[i]&1){
			if (x) f = 1;
			else x = i;
		}
		if (col[i]&1){
			if (y) f = 1;
			else y = i;
		}
	}
	
	if (!x && !y) cout << "OK";
	else if (x && y && !f) cout << x << " " << y;
	else cout << "Corrupt";
}
