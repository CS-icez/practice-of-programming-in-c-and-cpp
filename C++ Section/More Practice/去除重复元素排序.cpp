#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <set>
using namespace std;

int main() {
	int t;
	int  a[100];
	cin >> t;
	while(t--) {
		for(int i = 0;i < 12; ++i)
			cin >> a[i];
	sort(a, a+12);
	int* last = unique(a, a+12);
	for (int* p = a; p != last; ++p)
		cout << *p << " ";
	
	vector<int> b(a, a+12);
	auto c = b.begin();
std::copy(b.begin(), b.end(), c);
		cout << endl;

	}
	return 0;
}
