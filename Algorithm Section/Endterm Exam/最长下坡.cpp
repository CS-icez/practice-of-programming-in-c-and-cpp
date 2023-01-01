#include <bits/stdc++.h>
using namespace std;

int h[111];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> h[i];
		
	int res = 0;
	for (int i = 0; i < n; ++i){
		int cnt = 0;
		for (int j = 1; j < n; ++j)
			if (h[(i+j)%n] < h[(i+j-1)%n]) ++cnt;
			else break;
		res = max(res, cnt);
	}
	cout << res;
}
