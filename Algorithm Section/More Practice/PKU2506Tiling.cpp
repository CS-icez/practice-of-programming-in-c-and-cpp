#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

vi operator+(const vi& a, const vi& b){
	vi res;
	int t = 0;
    unsigned l = max(a.size(), b.size());
	for (unsigned i = 0; i < l; ++i){
		if (i < a.size()) t += a[i];
		if (i < b.size()) t += b[i];
		res.push_back(t%10);
		t /= 10;
	}
	if (t) res.push_back(t);
	return res;
}

ostream& operator<<(ostream& os, const vi& t){
	for (int i = t.size()-1; ~i; --i) os << t[i];
	return os;
}

const int N = 250;
vi dp[N+10];

int main(){
	dp[0].push_back(1);
	dp[1].push_back(1);
	
	for (int i = 2; i <= N; ++i)
		dp[i] = dp[i-1]+dp[i-2]+dp[i-2];	
	
	int n;
	while (cin >> n) cout << dp[n] << endl;
	
}
