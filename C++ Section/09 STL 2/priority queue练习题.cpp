#include <iostream>
#include <set>
using namespace std;

bool isPrime(int x){
	if (x == 1) return 0;
	for (int i = 2; i*i <= x; ++i)
		if (x%i == 0) return 0;
	return 1;
}

struct A{
	int n, p{0};
	A(int _n): n(_n){
		for (int i = 2; i*i <= _n; ++i){
			if (_n%i) continue;
			++p;
			do _n /= i; while (_n%i == 0);
		}
		if (_n != n && isPrime(_n)) ++p;
	}
	friend bool operator<(const A& a, const A& b){
		return a.p==b.p? a.n<b.n: a.p<b.p;
	}
};

set<A> s;

int main(){
	int n, t;
	cin >> n;
	
	while (n--){
		for (int i = 0; i < 10; ++i){
			cin >> t;
			s.insert(t);
		}
		auto p1 = s.begin(), p2 = --s.end();
		cout << p2->n << " " << p1-> n << endl;
		s.erase(p1); s.erase(p2);
	}
}
