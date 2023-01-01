#include <iostream>
using namespace std;

int main(){
	int a, b, i, j;
	cin >> a >> b >> i >> j;
	for (int k = i, t; k <= j; ++k){
		t = ~b&(1<<k);
		a &= ~(1<<k);
		a |= t;
	}
	cout << a;
}
