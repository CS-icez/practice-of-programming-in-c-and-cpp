#include <iostream>
#include <string>
using namespace std;

int f(int x){
	return x < 0? -1: x > 0;
}

int cmp(int x, int y){
	return x-y==5||y-x==5? f(x-y): f(y-x);
}

int main(){
	string str[3]{"draw", "A", "B"};
	int n, na, nb;
	cin >> n >> na >> nb;
	
	int a[na], b[nb];
	for (int i = 0; i < na; ++i) cin >> a[i];
	for (int i = 0; i < nb; ++i) cin >> b[i];
	
	int score = 0;
	while (n--) score += cmp(a[n%na], b[n%nb]);
	cout << str[score < 0? 2: score > 0];
}
