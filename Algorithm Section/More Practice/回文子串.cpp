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

bool check(const string& t){
	int len = t.size();
	for (int i = 0; i*2 <= len; ++i)
		if (t[i] != t[len-1-i]) return false;
	return true;
}

int main(){
	string s;
	int n;
	cin >> n;
	
	while (n--){
		cin >> s;
		int mlen = s.size();
		for (int len = mlen; len; --len)
			for (int i = 0; i <= mlen-len; ++i)
				if (check(s.substr(i, len))){
					cout << s.substr(i, len) << endl;
					goto end;
				}
	
	end:;
	}
}
