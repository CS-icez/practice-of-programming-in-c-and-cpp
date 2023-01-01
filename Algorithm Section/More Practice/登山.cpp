#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int h[N], l[N], r[N];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> h[i];
		
	for (int i = 1; i <= n; ++i){
		l[i] = 1;
		for (int j = 1; j < i; ++j)
			if (h[j] < h[i]) l[i] = max(l[j]+1, l[i]);
	}
	
	for (int i = n; i; --i){
		r[i] = 1;
		for (int j = n; j > i; --j)
			if (h[j] < h[i]) r[i] = max(r[j]+1, r[i]);
	}
	
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res = max(res, l[i]+r[i]-1);
	cout << res;
}
