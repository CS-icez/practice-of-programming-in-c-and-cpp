#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5842;
int a[N+5];

int main(){
	a[1] = 1;
	int p2, p3, p5, p7;
	p2 = p3 = p5 = p7 = 1;
	
	for (int i = 2; i <= N; ++i){
		a[i] = min({2*a[p2], 3*a[p3], 5*a[p5], 7*a[p7]});
		if (a[i] == 2*a[p2]) ++p2;
		if (a[i] == 3*a[p3]) ++p3;
		if (a[i] == 5*a[p5]) ++p5;
		if (a[i] == 7*a[p7]) ++p7;
	}
	
	int n;
	while (cin >> n, n){
		printf("The %d", n);
		if (n%10 == 1 && n%100 != 11)
			printf("st");
		else if (n%10 == 2 && n%100 != 12)
			printf("nd");
		else if (n%10 == 3 && n%100 != 13)
			printf("rd");
		else
			printf("th");
		printf(" humble number is %d.\n", a[n]);
	}
}
