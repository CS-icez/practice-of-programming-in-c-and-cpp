#include <iostream>
using namespace std;
int gcd(int a, int b) { // 计算两个数的最大公约数
    return (!b) ? a : gcd(b, a % b);
}
class Fraction {
    int p, q;
public:
	Fraction() = default;
	Fraction(int _p): p(_p), q(1){}
	Fraction(int _p, int _q): p(_p), q(_q){
		reduction();
	}
	
	Fraction& reduction(){
		int t = gcd(q, p);
		p /= t, q /= t;
		return *this;
	}
	
	friend istream& operator>>(istream& is, Fraction& t){
		is >> t.p >> t.q;
		t.reduction();
		return is;
	}
	friend ostream& operator<<(ostream& os, const Fraction& t){
		os << t.p;
		if (t.q != 1) os << "/" << t.q;
		return os;
	}
	
	friend Fraction operator*(const Fraction& a, const Fraction& b){
		Fraction ret(a.p*b.p, a.q*b.q);
		return ret.reduction();
	}
};

int main(){
    int testcases;
    cin >> testcases;
    while (testcases --) {
        Fraction a, b, two(2);
        cin >> a >> b;
        cout << a << " * " << b << " = " << a * b << endl;
        cout << "2 * " << a << " = " << two * a << endl;
        cout << b << " * 3 = " << b * 3 << endl;
    }
    return 0;
}
