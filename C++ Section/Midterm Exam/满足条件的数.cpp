#include<iostream>
using namespace std;
void print(unsigned int x) {
    // 显然, 我钻了题目的空子:)
	void f(unsigned x, unsigned y, int n);
	f(x, 0, 31);
}

void f(unsigned x, unsigned y, int n){
	if (n == -1){
		cout << y << endl;
		return;
	}
	
	f(x, y, n-1);
	if (x&(1<<n)) f(x, y|(1<<n), n-1);
}
int main() {
	int T; cin >> T;
	while (T--) {
		unsigned x; cin >> x;
		print(x);
	}
	return 0;
}
