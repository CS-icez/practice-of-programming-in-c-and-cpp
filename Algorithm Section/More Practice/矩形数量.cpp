#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <set>
using namespace std;

set<pair<int, int>> s;
set<int> sx, sy;
vector<int> x, y;

int main(){
	int T;
	cin >> T;
	
	while (T--){
		s.clear();
		sx.clear();
		sy.clear();
		x.clear();
		y.clear();
		
		int n;
		cin >> n;
		
		int a, b;
		while (n--){
			cin >> a >> b;
			if (!sx.count(a)) x.push_back(a), sx.insert(a);
			if (!sy.count(b)) y.push_back(b), sy.insert(b);
			s.insert({a, b});
		}
		
		int cnt = 0;
		int l1 = x.size(), l2 = y.size();
		
		for (int i1 = 0; i1 < l1; ++i1)
			for (int i2 = i1+1; i2 < l1; ++i2)
				for (int j1 = 0; j1 < l2; ++j1){
					if (!s.count({x[i1], y[j1]})) continue;
					if (!s.count({x[i2], y[j1]})) continue;
					for (int j2 = j1+1; j2 < l2; ++j2){
						if (!s.count({x[i1], y[j2]})) continue;
						if (!s.count({x[i2], y[j2]})) continue;
						++cnt;
					}
				}
		cout << cnt << endl;
	}
}
