#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define int unsigned

signed main(){
	int n = 0, minn = 1e9;
	
	string ori, dst;
	cin >> ori >> dst;
	int len = ori.length();
	
	if (len == 1){
		cout << (ori[0] != dst[0]);
		return 0;
	}
	
	for (int i = 0; i < len; ++i)
		ori[i] = (ori[i]!=dst[i]);	//0 is good
	
	string cur = ori;
	for (int i = 1; i < len; ++i){
		if (!cur[i-1]) continue;
		cur[i] ^= 1;
		cur[i-1] ^= 1;
		if (i != len-1) cur[i+1] ^= 1;
		++n;
	}
	if (!cur[len-1]) minn = n;
	
	cur = ori, n = 1;
	cur[0] ^= 1, cur[1] ^= 1;
	for (int i = 1; i < len; ++i){
		if (!cur[i-1]) continue;
		cur[i] ^= 1;
		cur[i-1] ^= 1;
		if (i != len-1) cur[i+1] ^= 1;
		++n;
	}
	if (!cur[len-1]) minn = min(n, minn);
	
	if (minn != 1e9) cout << minn;
	else cout << "impossible";
}
