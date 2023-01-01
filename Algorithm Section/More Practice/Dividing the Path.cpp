#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1011, L = 1e6+10, INF = 0x3f3f3f3f;
int a, b, n, l;
int unavi[L];
int dp[L];
int q[L], head, tail;	//increasing

int main(){
	cin >> n >> l;
	if (l&1){
		cout << -1;
		return 0;
	}
	cin >> a >> b;
	
	for (int i = 0, s, e; i < n; ++i){
		cin >> s >> e;
		++unavi[s+1], --unavi[e];
	}
	for (int i = 1; i <= l; ++i)
		unavi[i] += unavi[i-1];
	
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0, tail = 1;
	
	for (int i = 2*a; i <= l; i += 2){
		if (!unavi[i]){
			while (head < tail && q[head] < i-2*b)
    			++head;
    		if (head < tail) dp[i] = dp[q[head]]+1;
		}
		while (head < tail && dp[q[tail-1]] >= dp[i-2*a+1])
			--tail;
		q[tail++] = i-2*a+2;
	}
	
	cout << (dp[l]>=INF? -1: dp[l]);
}
