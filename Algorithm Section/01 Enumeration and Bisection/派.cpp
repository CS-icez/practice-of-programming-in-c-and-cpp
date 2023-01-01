#include <iostream>
#include <cmath>
using namespace std;

int N, F;
double v[10010];
const double pi = acos(-1.0), eps = 1e-5;

bool check(double x){
	int n = 0;
	for (int i = 0; i < N; ++i)
		if ((n+=v[i]/x) >= F) return true;
	return false;
}

int main(){
	cin >> N >> F;
	++F;
	for (int i = 0, t; i < N; ++i){
		cin >> t;
		v[i] = pi*t*t;
	}
	
	double l = 0, r = 1e9, mid;
	while (r-l > 1e-5){
		mid = (l+r)/2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%.3f", l+1e-8);
}
