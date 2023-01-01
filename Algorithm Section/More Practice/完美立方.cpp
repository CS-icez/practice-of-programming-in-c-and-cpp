#include <iostream>
using namespace std;

#define f(x) (x*x*x)

int main(){
	int n;
	cin >> n;
	
	for (int a = 1; a <= n; ++a)
		for (int b = 2; b <= a; ++b)
			for (int c = b; c <= a; ++c)
				for (int d = c; d <= a; ++d)
					if (f(a) == f(b)+f(c)+f(d))
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d); 
}
