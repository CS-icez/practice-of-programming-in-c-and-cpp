#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

using vi = vector<int>;
#define int unsigned

char sq[55];
vi dp[55][55];	//前i位放j个加号的最小值

vi toVector(int l, int r){
	vi res;
	for (; r >= l; --r) res.push_back(sq[r]-'0');
	return res;
}

vi operator+(const vi& a, const vi& b){
	vi res;
	int t = 0, l = max(a.size(), b.size());
	for (int i = 0; i < l; ++i){
		if (a.size() > i) t += a[i];
		if (b.size() > i) t += b[i];
		res.push_back(t%10);
		t /= 10;
	}
	while (t) res.push_back(t%10), t /= 10;
	return res;
}

bool operator<(const vi& a, const vi& b){
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = a.size()-1; ~i; --i)
		if (a[i] != b[i]) return a[i] < b[i];
	return false;
}

ostream& operator<<(ostream& os, const vi& t){
	for (int i = t.size()-1; ~i; --i) os << t[i];
	return os;
}

signed main(){
	int m;
	
	while (cin >> m){
		cin.ignore();
		cin.getline(sq+1, 55);
		
		int l = strlen(sq+1);
		
		for (int i = 1; i <= l; ++i)
			dp[i][0] = toVector(1, i);
		
		for (int i = 1; i <= l; ++i)
			for (int j = 1; j <= i-1; ++j){
				dp[i][j].resize(100, 1);
				for (int k = j; k <= i-1; ++k){  // //枚举最后一个元素在哪个数字之后
					vi t = dp[k][j-1]+toVector(k+1, i);
					if (t < dp[i][j]) dp[i][j] = t;
				}
			}
		cout << dp[l][m] << endl;	
	}
}
