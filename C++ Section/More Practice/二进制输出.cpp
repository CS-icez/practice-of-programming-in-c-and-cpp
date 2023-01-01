#include <iostream>
#include <string>
using namespace std;
string dec2bin(int x){
	string s;
	for (int i = 30; ~i; --i)
		s += ((x>>i)&1)+'0';
	return s;
}
int main(){
	int n;
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		cout << dec2bin(x) << endl;
	}
	return 0;
}
