#include <iostream>
using namespace std;

int a[1010];

int main(){
	int n;
	cin >> n;
	
	int sum = 2;
	for (; (sum-1)*sum/2 < n; ++sum);
	n -= (sum-1)*(sum-2)/2;
	
	int p, q;
	if (sum&1) p = n, q = sum-n;
	else p = sum-n, q = n;
	cout << p << "/" << q;
}
