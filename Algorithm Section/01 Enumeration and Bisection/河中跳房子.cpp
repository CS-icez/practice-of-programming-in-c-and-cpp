#include <iostream>
using namespace std;

int L, M, N;
int d[50010];

bool check(int x){
	int start = 0, n = 0;
	for (int i = 0; i < N; ++i){
		if (d[i]-start < x) ++n;
		else start = d[i];
	}
	if (L-start < x) ++n;
	return n <= M;
}

int main(){
	cin >> L >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> d[i];
		
	int l = 0, r = L, mid;
	while (l < r){
		mid = (l+r+1)>>1;
		if (check(mid)) l = mid;
		else r = mid-1;
	}
	cout << l;
}
