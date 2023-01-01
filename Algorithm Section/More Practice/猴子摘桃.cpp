#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

int peach[111], bee[111];
int cnt, res;


int main(){
	int n;
	while (cin >> n, ~n){
		for (cnt = 0, res = 0; cin >> peach[cnt] >> bee[cnt], ~bee[cnt]; ++cnt);
		
		for (int i = 0; i < cnt; ++i){
			int tot = 0;
			for (int j = i, left = n; j < cnt && left >= bee[j]; ++j)
				left -= bee[j], tot += peach[j];
			res = max(res, tot);
		}
		cout << res << endl;
	}
}
