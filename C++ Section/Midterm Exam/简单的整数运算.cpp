#include <stdio.h>
#include <iostream>
using namespace std;
class MyInteger{
public:
  unsigned char C;
  MyInteger(unsigned char c='0'): C(c) {}
	MyInteger operator*(const MyInteger& t){
		return MyInteger((C-'0')*(t.C-'0')+'0');
	}
	MyInteger operator+(const MyInteger& t){
		return MyInteger(C+t.C-'0');
	}
	operator int(){
		return C-'0';
	}
};

int main() { 
  unsigned char m,n;
  cin >> m >> n;
  MyInteger n1(m), n2(n);
  MyInteger n3;
  n3 = n1*n2;
  MyInteger n4 = n1+n2+n3;
  cout << int(n3) << endl;
  cout << n1+n2+n3 << endl;
  return 0;
}
