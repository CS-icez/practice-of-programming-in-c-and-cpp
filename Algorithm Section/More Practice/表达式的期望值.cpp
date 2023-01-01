#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <queue>
using namespace std;

const int N = 222;
int n;
int a[N];
char o[N];
double p[N];

bool bitOpExp(bool l, char op, bool r){
	switch (op){
		case '&': return l&r;
		case '|': return l|r;
		case '^': return l^r;
	}
}

double calcExp(int bit){
	double exp = !!(a[0]&(1<<bit));
	
	for (int i = 1; i <= n; ++i){
		bool t = a[i]&(1<<bit);
		exp = p[i]*exp+(1-p[i])*(exp*bitOpExp(1, o[i], t)+(1-exp)*bitOpExp(0, o[i], t));
	}
		
	return exp;
}

int main(){
	int T = 0;
	while (cin >> n){
++T;
		for (int i = 0; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
			cin >> o[i];
		for (int i = 1; i <= n; ++i)
			cin >> p[i];
		
		double res = 0;
		for (int i = 0; i < 20; ++i)
			res += (1<<i)*calcExp(i);
		printf("Case %d:\n%.6f\n", T, res);
	}
}
