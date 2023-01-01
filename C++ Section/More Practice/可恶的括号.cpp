#include <cstdio>
#include <iostream>
using namespace std;

class f {
public:
	int n, m;
	f(int _n): n(_n){
	}
	f(int _n, int _m): n(_n), m(_m){
	}
	int operator()(int t){
		return t-n;
	}
	operator int(){
		return n*m;
	}
};

int main() {
  cout << f(3)(5) << endl;
  cout << f(4)(10) << endl;
  cout << f(114)(514) << endl;
  cout << f(9,7) << endl;
  cout << f(2,3) << endl;
  cout << f(2,5) << endl;
}
