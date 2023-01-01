#include <iostream>
using namespace std;
class Number {
public: 
    int num;
    Number(int n): num(n) {}
	operator int(){return num;}
	Number operator*(int n){return Number(num*n);}
	bool operator==(const Number& t){return num == t.num;}
};
int main() {
	int t;
	int m,n;
	cin >> t;
	while(t--) {
	    cin >> m>> n;
	    Number n1(m), n2 = n1 * n;
	    if( m * n == n2 )
	    	cout << n2 << endl;
	}
    return 0;
}
