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
#include <stack>
using namespace std;

#define x first
#define y second

const int N = 1011;
using pii = pair<int, int>;
pii a[N];

int calc(pii a, pii b){
	return min(b.y, a.y)-b.x+1;
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y;
	sort(a, a+n);
	
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j){
			if (a[i].y < a[j].x) break;
			res = max(res, calc(a[i], a[j]));
		}
					
	cout << res;
}
