#include <bits/stdc++.h>
using namespace std;

const int N = 53;
int n, l1, l2;
char s[N], p[N];

bool f(int s1, int s2){
	if (s1 == l1 && s2 == l2) return true;
	
	if (p[s2] == '?'){
		if (s1 == l1) return false;
		return f(s1+1, s2+1);
	}
	else if (p[s2] == '*'){
		for (int i = s1; i <= l1; ++i)
			if (f(i, s2+1)) return true;
		return false;
	}
	else{
		if (s[s1] != p[s2]) return false;
		return f(s1+1, s2+1);
	}
	return false;
}

int main(){
	cin >> n;
	while (n--){
		memset(s, 0, sizeof s);
		memset(p, 0, sizeof p);
		cin >> s >> p;
		l1 = strlen(s), l2 = strlen(p);
		cout << (f(0, 0)? "yes": "no") << endl;
	}
}
