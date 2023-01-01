#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;
class MyQueue
{
private:
	const int k;
	multiset<int, greater<int>> s;
public:
	MyQueue(int _k): k(_k){}
	friend istream& operator>>(istream& is, MyQueue& q){
		int t;
		is >> t;
		if (!(t&1)) q.s.insert(t);
		return is;
	}
	friend ostream& operator<<(ostream& os, MyQueue& q){
		int i = q.k;
		auto it = q.s.begin();
		while (i--) os << *it++ << " ";
		return os;
	}
};
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		MyQueue q(k);
		for (int i = 0; i < n; ++i)
			cin >> q;
		cout<<q;
		cout << endl;
	}
	return 0; 
}
