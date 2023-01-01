#include<iostream>
using namespace std;
int count(unsigned int x) {
	int cnt = 0;
	for (int i = 0; i < 32; ++i)
		if (x&(1<<i)) ++cnt;
	return cnt;
}
int main() {
	int T; cin >> T;
	while (T--) {
		unsigned x; cin >> x;
		cout << count(x) << endl;
	}
	return 0;
}
