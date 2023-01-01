#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	int n;
	cin >> n;
	
	int res = 1e9;
	for (int a = 1; a*a*a <= n; ++a)
		for (int b = a; b*b*a <= n; ++b){
			int c = n/(a*b);
			if (a*b*c != n) continue;
			res = min(res, 2*(a*b+b*c+c*a));
		}
	cout << res;
}
