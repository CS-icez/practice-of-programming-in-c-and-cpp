#include <iostream>
#include <algorithm>
using namespace std;

string p, q, r;

int main(){
	cin >> p >> q >> r;
	
	unsigned m = 0;
	for (unsigned i = 0; i < p.size(); ++i)
		p[i] -= '0', m = max(m, (unsigned)p[i]);
	for (unsigned i = 0; i < q.size(); ++i)
		q[i] -= '0', m = max(m, (unsigned)q[i]);
	for (unsigned i = 0; i < r.size(); ++i)
		r[i] -= '0', m = max(m, (unsigned)r[i]);
		
	for (int i = m+1; i <= 16; ++i){
		int a = 0, b = 0, c = 0;
		for (unsigned j = 0; j < p.size(); ++j)
			a = a*i+p[j];
		for (unsigned j = 0; j < q.size(); ++j)
			b = b*i+q[j];			
		for (unsigned j = 0; j < r.size(); ++j)
			c = c*i+r[j];
		if (a*b == c){
			cout << i;
			return 0;
		}		
	}
	cout << 0;
}
