#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

const int N = 1111;
char m[N][N];



int main(){
	int n;
	while (cin >> n, ~n){
		memset(m, ' ', sizeof m);	//Note here
		m[1][1] = 'X';
		int w = 1;
		
		for (int i = 2; i <= n; ++i){
			for (int r = 1; r <= w; ++r)
				for (int c = 1; c <= w; ++c)
					m[2*w+r][c] = m[r][2*w+c]
								= m[w+r][w+c]
								= m[2*w+r][2*w+c]
								= m[r][c];
		w *= 3;
		}
		for (int i = 1; i <= w; ++i){
			m[i][w+1] = 0;
			puts(m[i]+1);
		}
		cout << '-' << endl;
	}
}
