#include <bits/stdc++.h>
using namespace std;

const int N = 111;
bool banana[N];

int main(){
	int T;
	cin >> T;
	while (T--){
		memset(banana, 0, sizeof banana);
		
		int n, m, t;
		cin >> n >> m;
		while (n--){
			cin >> t;
			banana[t] = 1;
		}
		
		int res = 0;
		for (int i = 1, j; i <= 101-res; ++i){
			int cnt = 0;
			for (j = i; j <= 100; ++j)
				if (banana[j] && cnt++ == m)
					break;
			res = max(res, j-i);
		}
		cout << res << endl;
	}
}
