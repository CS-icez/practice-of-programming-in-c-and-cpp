#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
double f(){
	cin >> s;
	switch (s[0]){
		case '+': return f()+f(); break;
		case '-': return f()-f(); break;
		case '*': return f()*f(); break;
		case '/': return f()/f(); break;
		default: return atof(s.c_str()); break;
	}
}

int main(){
	printf("%f\n", f());
}
