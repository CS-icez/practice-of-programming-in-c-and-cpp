#include <cstdio>
#include <iostream>
using namespace std;

class f {
public:
	int m, n;
	f(int a): m(a){
		
	}
	f(int a, int b): m(a), n(b){
		
	}
	operator int(){
		return m*n;
	}
	class g{
	public:
		int a, b;
		g(int t1, int t2): a(t1), b(t2){
			
		}
		operator int(){
			return a+b;
		}
		int operator()(int t){
			return a+b+t;
		}
	};
	
	g operator()(int t){
		return g(m, t);
	}
};

int main() {
  cout << f(4)(5) << endl;
  cout << f(64)(36) << endl;
  cout << f(3)(5)(7) << endl;
  cout << f(3,8) << endl;
  cout << f(15,3) << endl;
  cout << f(7,10) << endl;
}
