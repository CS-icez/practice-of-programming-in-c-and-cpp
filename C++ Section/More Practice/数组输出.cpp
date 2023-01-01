#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;
template <class T>
class Print{
private:
	unsigned n;
public:
	Print(int _n): n(_n){}
	
	Print& operator=(const Print&){return *this;}
	Print operator+(const T& t){
		cout << t;
		if (!--n) cout << endl;
		return *this;
	}
};
int main(){
	string s[20];
	int num[20];
	int m,n;
	
	while(cin >> m >> n){
		for(int i=0; i<m; i++){
			cin >> s[i];
		}
		accumulate(s, s+m, Print<string>(m));
		for(int i=0; i<n; i++){
			cin >> num[i];
		}
		accumulate(num, num+n, Print<int>(n));
	}
}
