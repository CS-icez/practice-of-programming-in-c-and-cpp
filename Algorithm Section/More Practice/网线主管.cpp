#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
const double eps = 1e-7;
int n, k;
int len[N];

bool check(int x){
	int res = 0;
	for (int i = 0; i < n; ++i)
		res += len[i]/x;
	return res >= k;
}

int main(){
	cin >> n >> k;
	double t;
	for (int i = 0; i < n; ++i){
		cin >> t;
		len[i] = t*100;
	}
		
	int l = 0, r = 1e7, mid;
	while (l < r){
		mid = (l+r+1)>>1;
		if (check(mid)) l = mid;
		else r = mid-1;
	}
	
	printf("%.2f", r/100.0);
}
