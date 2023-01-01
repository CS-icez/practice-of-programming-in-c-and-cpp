#include <bits/stdc++.h>
using namespace std;

const int N = 22222, M = 22222, P = 50022, V = 50000;	//kinds of item, kinds of box, energy
int t[N], u[N], cnt1;	//energy, weight
int x[M], y[M], cnt2;	//capacity, cost
int dp1[P];	//with pre i item, supply at least j energy, min weight
int dp2[V+50];	//with pre i box, no more then j cost, max capacity

int main(){
	int T;
	cin >> T;
	
	while (T--){
		int n, m, p;
		cin >> n >> m >> p;
		
		cnt1 = cnt2 = 0;
		
		for (int i = 1, a, b, c; i <= n; ++i){
			cin >> a >> b >> c;
			int step = 1;
			while (c >= step){
				++cnt1;
				t[cnt1] = step*a;
				u[cnt1] = step*b;
				c -= step;
				step <<= 1;	
			}
			if (c){
				++cnt1;
				t[cnt1] = c*a;
				u[cnt1] = c*b;
			}
		}
		
		for (int i = 1, a, b, c; i <= m; ++i){
			cin >> a >> b >> c;
			int step = 1;
			while (c >= step){
				++cnt2;
				x[cnt2] = step*a;
				y[cnt2] = step*b;
				c -= step;
				step <<= 1;
			}
			if (c){
				++cnt2;
				x[cnt2] = c*a;
				y[cnt2] = c*b;
			}
		}
		
		memset(dp1, 0x3f, sizeof dp1);
		dp1[0] = 0;
		for (int i = 1; i <= cnt1; ++i){
			for (int j = p; j >= t[i]; --j)
				dp1[j] = min(dp1[j], dp1[j-t[i]]+u[i]);
			for (int j = t[i]-1; j > 0; --j)
				dp1[j] = min(dp1[j], u[i]);
		}
		
		memset(dp2, 0, sizeof dp2);
		for (int i = 1; i <= cnt2; ++i)
			for (int j = V; j >= y[i]; --j)
				dp2[j] = max(dp2[j], dp2[j-y[i]]+x[i]);
				
		if (dp2[V] < dp1[p]) cout << "FAIL" << endl;
		else{
			int cur = 0, step = 1;
			while (step){
				while (cur+step > V) step >>= 1;
				if (dp2[cur+step] < dp1[p]){	
					cur += step;
					step <<= 1;
				}
				else step >>= 1;
			}
			cout << (cur+1) << endl;
		}
	}
}
