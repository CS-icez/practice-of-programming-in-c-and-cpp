#include <iostream>
using namespace std;
class MyCin
{
public:
	bool valid{true};
	operator bool(){return valid;}
	MyCin& operator>>(int& x){
		if (!valid) return *this;
		cin >> x;
		if (!~x) valid = 0;
		return *this;
	}
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}
