#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <queue>
using namespace std;

const int N = 1011;
char s[N];
int zero[N], one[N];

int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> (s+1);	//note here
		int len = strlen(s+1);
		memset(zero, 0, sizeof zero);
		memset(one, 0, sizeof one);
		
		for (int i = 1; i <= len; ++i)
			zero[i] = zero[i-1]+(s[i]=='1');
		for (int i = len; i; --i)
			one[i] = one[i+1]+(s[i]=='0');
		
		int res = 1e9;	
		for (int i = 1; i <= len; ++i)
			res = min(res, zero[i]+one[i+1]);
			
		cout << res << endl;
		
	}
}
