#include <bits/stdc++.h>
using namespace std;

const int N = 1011;
int h[N];
int dst[N], beg[N];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> h[i];
	
	
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j < i; ++j)
			if (h[j] >= h[i]) dst[i] = max(dst[i], dst[j]);
		dst[i] += 1;
	}
	
	for (int i = n; i; --i){
		for (int j = n; j > i; --j)
				if (h[j] <= h[i]) beg[i] = max(beg[i], beg[j]);
			beg[i] += 1;
	}
	
	int res = beg[1];
	for (int i = 2; i <= n; ++i){
		dst[i-1] = max(dst[i-1], dst[i-2]);
		res = max(res, dst[i-1]+beg[i]);
	}
		
	cout << res;
}
