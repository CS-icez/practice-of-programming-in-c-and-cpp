#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <queue>
using namespace std;

int n, m;
double w[1011];

int calc(int x){
	int res = 0;
	for (int i = 0; i < n; ++i)
		res += ceil(w[i]/x);
	return res;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> w[i];
		
	int l = 1, r = 1e8, mid;
	while (l < r){
		mid = (l+r)>>1;
		if (calc(mid) <= m) r = mid;
		else l = mid+1;
	}
	cout << r;
}
