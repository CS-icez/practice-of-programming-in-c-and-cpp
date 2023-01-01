#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	
	while (T--){
		int n;
		cin >> n;
		
		long long pre = 0, cur = 0, sup = 0;
		for (int i = 1, t; i <= n; ++i){
			scanf("%d", &t);
			pre = cur;
			cur = sup + t;
			if (pre > sup) sup = pre;
		}
		cout << max(sup, cur) << endl;
	}
}
