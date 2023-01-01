#include <iostream>
using namespace std;

int a[666];

int gcd(int b, int c){
	return c? gcd(c, b%c): b;
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i] < a[j] && gcd(a[i], a[j]) == 1)
				++cnt;
	cout << cnt;
}
