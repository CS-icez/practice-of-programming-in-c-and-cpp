#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
public:
	int a[205]{};
	int len{0};
	CHugeInt(const char* t){
		for (; t[len]; ++len);
		for (int i = len-1, j = 0; ~i; --i, ++j)
			a[j] = t[i]-'0';
	}
	CHugeInt(int n){
		len = 0;
		while (n){
			a[len] = n%10;
			n /= 10;
			++len;
		}
	}
	friend ostream& operator<<(ostream& os, const CHugeInt& t){
		for (int i = t.len-1; ~i; --i)
			os << t.a[i];
		return os;
	}
	
	friend CHugeInt operator+(const CHugeInt& t, const CHugeInt& b){
		int l = max(t.len, b.len), tem = 0, i = 0;
		CHugeInt res(0);
		for (; i < l; ++i){
			if (i < t.len) tem += t.a[i];
			if (i < b.len) tem += b.a[i];
			res.a[i] = tem%10;
			tem /= 10;
		}
		if (tem) res.a[i++] = tem;
		res.len = i;
		return res;
	}
	
	CHugeInt& operator+=(const CHugeInt& t){
		return *this = *this+t;
	}
	
	CHugeInt& operator++(){
		return *this = *this+1;
	}
	
	CHugeInt operator++(int){
		CHugeInt t = *this;
		*this = *this+1;
		return t;
	}
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
