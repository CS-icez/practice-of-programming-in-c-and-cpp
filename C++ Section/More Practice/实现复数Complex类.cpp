#include <iostream>
using namespace std;
class Complex{
private:
	int r{0}, i{0};
public:
	Complex() = default;
	Complex(const char* s){
		for (; *s != '+'; ++s) r = r*10+*s-'0';
		for (++s; *s != 'i'; ++s) i = i*10+*s-'0';
	}
	Complex(const Complex& t): r(t.r), i(t.i){}
	Complex(int _r, int _i = 0): r(_r), i(_i){}
	Complex& operator=(const Complex& t) = default;
	
	friend ostream& operator<<(ostream& os, const Complex& t){
		if (t.r){
			os << t.r;
			if (t.i > 0) os << "+";
			else if (t.i < 0) os << "-";	
		}
		if (t.i) os << t.i << "i";
		if (!t.r && !t.i) os << 0;
		return os;
	}
	friend Complex operator+(const Complex& a, const Complex& b){
		return Complex(a.r+b.r, a.i+b.i);
	}
	friend Complex operator-(const Complex& a, const Complex& b){
		return Complex(a.r-b.r, a.i-b.i);
	}
	friend Complex operator*(const Complex& a, const Complex& b){
		return Complex(a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r);
	}
	Complex operator+=(const Complex& t){
		return *this = *this+t;
	}
	Complex operator-=(const Complex& t){
		return *this = *this-t;
	}
	Complex operator*=(const Complex& t){
		return *this = *this*t;
	}
};
int main() {
	Complex c1;
	Complex c2("3+2i"); // 用字符串初始化时，只需考虑"a+bi"的形式，其中a和b都是1位数字
	Complex c3(c2);
	Complex c4(-15);
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c2 + c4 << endl;
	cout << c2 - c3 << endl;
	cout << c2 * c3 << endl;
	c2 += c4;
	cout << c2 << endl;
	c2 -= -12;
	cout << c2 << endl;
	c3 *= c3;
	cout << c3 << endl;
	return 0;
}
