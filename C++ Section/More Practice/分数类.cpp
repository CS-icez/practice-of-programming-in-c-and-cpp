#include <iostream>
using namespace std;
int gcd(int x, int y){
	return x%y==0?y:gcd(y,x%y);
}
class Fraction
{
    int num, den;
public:
	Fraction(int _num, int _den = 1){
		int t = gcd(_num, _den);
		num = _num/t, den = _den/t;
	}
	
	friend Fraction operator*(const Fraction& a, const Fraction& b){
		int p = a.num*b.num, q = a.den*b.den;
		int t = gcd(p, q);
		return Fraction(p/t, q/t);
	}
	friend Fraction operator/(const Fraction& a, const Fraction& b){
		return a*Fraction(b.den, b.num);
	}
	
	Fraction& operator*=(const Fraction& t){
		return *this = (*this)*t;
	}
	Fraction& operator/=(const Fraction& t){
		return *this = (*this)/t;
	}
	
	operator float(){
		return (float)num/den;
	}
	
	friend ostream& operator<<(ostream& os, const Fraction& t){
		return os << t.num << "/" << t.den;
	}
};
 
int main() {
	int a,b,c;
	cin >> a >> b >> c;
    Fraction f(a, b), g(c);
	f *= g;
	cout << f << endl;
	f /= g;
	cout << f << endl;
	f = f * f;
	cout << f << endl;
	f = f / g;
	cout << f << endl;
	cout << (float) f << endl;
    return 0;
}
