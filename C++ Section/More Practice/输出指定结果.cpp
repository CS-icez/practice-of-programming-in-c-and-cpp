#include <iostream>
using namespace std;

class A {
public:
	int n;
	A(int _n): n(_n){}
	operator int(){return n;}
	A& operator-=(const A& t){
		n -= t.n;
		return *this;
	}
	A& operator+=(const A& t){
		n += t.n;
		return *this;
	}
	int& getValue(){return n;}
};

int main() {
	int t;
	cin >> t;
	while(t-- ) {
		int m,n,k;
		cin >> m >> n >> k;	
	    A a(m);
	    A b = a;
	    cout << b << endl;
	    cout << (a += b -= n) << endl;
	    cout << a.getValue() << endl;
	    a.getValue() = k;
	    cout << a << endl;
	} 
	return 0;
}
