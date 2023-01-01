#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

int n, x;
int a[10], cur[10];

bool win(){
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		if (cur[i]-a[i] >= x) ++cnt;
	return cnt > n/2;
}

int main(){
	cin >> n >> x;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
		
	memcpy(cur, a, sizeof a);
	sort(cur, cur+n);
	
	do{
		if (!win()) continue;
		for (int i = 0; i < n; ++i)
			cout << cur[i] << " \n"[i==n-1];
	} while (next_permutation(cur, cur+n));
}
