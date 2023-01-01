#include <iostream>
#include <iterator>
using namespace std;

template<class T1, class T2>
void Copy(T1 s, T1 e, T2 x) {
    for(; s != e; ++s, ++x)
        *x = *s;
}
class Fib{
private:
	int n;
	int a{1}, b{1}, c{0};	//a=b+c
public:
	Fib(int _n): n(_n){}
	void operator++(){
		++n;
		a = b+c, c = b, b = a;
	}
	bool operator!=(const Fib& t){
		return n != t.n;
	}
	int operator*(){
		return a;
	}
};
int main() {
	while(true) {
		int n;
		cin >> n;
		if(n == 0)
			break;
		
	    Fib f1(1), f2(n);
	    ostream_iterator<int> it(cout, " ");
	    Copy(f1, f2, it);
	    cout << endl;
	}
	return 0;
}
